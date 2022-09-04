#include "raylib.h"
#include "Player.h"
#include "Pipe.h"


// - - - - - - - - - - - - - - - - - - - - - -
// GLOBAL VARIABLES

Player player;
Pipe pipe;
int score = 0;
int highScore = 0;

Sound startSound;

enum class GameStates: int {
	MainMenuState = 0,
	MainGameState = 1,
	LoseState = 2
} currentState;

// FUNCTIONS

void UpdateMenu();
void DrawMenu();
void UpdateGame();
void DrawGame();
void UpdateLoseScreen();
void DrawLoseScreen();
void UpdateDrawFrame();
void CheckCollisionPlayerPipe();
void DrawScoreBox();

// - - - - - - - - - - - - - - - - - - - - - -

int main()
{
	int screenWidth = 500;
	int screenHeight = 500;
	SetTargetFPS(60);

	// Initialize
	InitWindow(screenWidth, screenHeight, "Flappy");
	InitAudioDevice();

	currentState = GameStates::MainMenuState;

	// Load Resources
	player.jumpSound = LoadSound("resources/audio/jump.wav");
	player.bumpSound = LoadSound("resources/audio/bump.wav");
	player.scoreSound = LoadSound("resources/audio/score.wav");

	startSound = LoadSound("resources/audio/start.wav");

	// Initialize Objects
	player.Start();
	pipe.Start(1.5f);

	while (!WindowShouldClose())
	{
		UpdateDrawFrame();
	}

	// Unload Resources
	UnloadSound(player.jumpSound);
	UnloadSound(player.bumpSound);
	UnloadSound(player.scoreSound);
	UnloadSound(startSound);

	// Close
	CloseAudioDevice();
	CloseWindow();
	return 0;
}

void UpdateDrawFrame()
{
	switch(currentState) {
		case GameStates::MainMenuState:
			UpdateMenu();
			DrawMenu();
			break;
		case GameStates::MainGameState:
			UpdateGame();
			DrawGame();
			break;
		case GameStates::LoseState:
			UpdateLoseScreen();
			DrawLoseScreen();
			break;
	}
}

void UpdateMenu()
{
	if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(0))
	{
		PlaySound(startSound);
		currentState = GameStates::MainGameState;
		player.Start();
		pipe.Start(1.5f);
		score = 0;
	}
}

void DrawMenu()
{
	BeginDrawing();

	ClearBackground(BLACK);

	const char* title = "BOX";
	const char* desc = "TAP to Start";
	int titleWidth = MeasureText(title, 50);
	int descWidth = MeasureText(desc, 20);
	Vector2 titlePos = { (float)(GetScreenWidth() - titleWidth) / 2, (float)GetScreenHeight() / 3 };
	Vector2 descPos = { (float)(GetScreenWidth() - descWidth) / 2, (float)GetScreenHeight() * 2 / 3 };
	DrawText(title, titlePos.x, titlePos.y, 50, WHITE);
	DrawText(desc, descPos.x, descPos.y, 20, LIGHTGRAY);

	EndDrawing();
}

void UpdateGame()
{
	player.Update();
	pipe.Update();
	CheckCollisionPlayerPipe();
	if (IsKeyPressed(KEY_ESCAPE))
	{
		currentState = GameStates::MainMenuState;
	}
}
void DrawGame()
{
	BeginDrawing();

	ClearBackground(BLACK);

	player.Draw();
	pipe.Draw();
	DrawScoreBox();

	//DrawFPS(10, 10);

	EndDrawing();
}

void UpdateLoseScreen()
{
	if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(0))
	{
		PlaySound(startSound);
		currentState = GameStates::MainGameState;
		player.Start();
		pipe.Start(1.5f);
		score = 0;
	}
	if (IsKeyPressed(KEY_ESCAPE))
	{
		currentState = GameStates::MainMenuState;
	}
}

void DrawLoseScreen()
{
	BeginDrawing();

	ClearBackground(BLACK);

	player.Draw();
	pipe.Draw();

	float width = 300.0f;
	float height = 300.0f;
	Rectangle rect = { 100, 100, width, height };

	DrawRectangleRounded(rect, 0.1f, 1, BLACK);
	DrawRectangleRoundedLines(rect, 0.1f, 1, 5.0f, WHITE);

	const char* title = "Game Over";
	const char* desc = "TAP to Try Again";
	int titleWidth = MeasureText(title, 50);
	int descWidth = MeasureText(desc, 20);
	Vector2 titlePos = { (float)(GetScreenWidth() - titleWidth) / 2, (float)GetScreenHeight() / 3 - 50 };
	Vector2 descPos = { (float)(GetScreenWidth() - descWidth) / 2, (float)GetScreenHeight() * 3 / 5 - 100 };
	DrawText(title, titlePos.x, titlePos.y, 50, WHITE);
	DrawText(desc, descPos.x, descPos.y, 20, LIGHTGRAY);

	const char* scoreText = TextFormat("%i", score);
	const char* highScoreText = TextFormat("High Score: %i", highScore);
	int scoreTextWidth = MeasureText(scoreText, 50);
	int highScoreTextWidth = MeasureText(highScoreText, 20);
	Vector2 scoreTextPos = { (float)(GetScreenWidth() - scoreTextWidth) / 2, (float)GetScreenHeight() / 3 + 100 };
	Vector2 highScoreTextPos = { (float)(GetScreenWidth() - highScoreTextWidth) / 2, (float)GetScreenHeight() * 3 / 5 + 50};
	DrawText(scoreText, scoreTextPos.x, scoreTextPos.y, 50, WHITE);
	DrawText(highScoreText, highScoreTextPos.x, highScoreTextPos.y, 20, LIGHTGRAY);

	EndDrawing();
}

void Death()
{
	pipe.speed = 0.0f;
	player.jumpHeight = 0.0f;
	player.isAlive = false;
	if (!player.playDeathSound)
	{
		PlaySound(player.bumpSound);
		player.playDeathSound = true;
	}
	if (score > highScore)
	{
		highScore = score;
	}
	currentState = GameStates::LoseState;
}

void CheckCollisionPlayerPipe()
{
	if (player.OnCollideGround())
	{
		Death();
	}
	if (CheckCollisionRecs(player.rect, pipe.rectUp) || CheckCollisionRecs(player.rect, pipe.rectDown))
	{
		Death();
	}
	if (CheckCollisionRecs(player.rect, pipe.scoreRect) && !player.scored && player.isAlive)
	{
		score += 1;
		player.scored = true;
		PlaySound(player.scoreSound);
	}
	if (!CheckCollisionRecs(player.rect, pipe.scoreRect))
	{
		player.scored = false;
	}
}

void DrawScoreBox()
{
	float width = 150.0f;
	float height = 100.0f;
	Rectangle rect = { 10, GetScreenHeight() - height - 10, width, height };

	//DrawRectangleRounded(rect, 0.1f, 1, BLACK);
	//DrawRectangleRoundedLines(rect, 0.1f, 1, 5.0f, WHITE);

	const char* scoreText = TextFormat("%i", score);
	int textWidth = MeasureText(scoreText, 50) / 2;
	DrawText(scoreText, (int)(width / 2) - textWidth - (int)rect.x, (int)rect.y + (int)height / 2 - 25, 50, WHITE);
}