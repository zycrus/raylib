#include "raylib.h"
#include "Player.h"
#include "Pipe.h"


// - - - - - - - - - - - - - - - - - - - - - -
// GLOBAL VARIABLES

Player player;
Pipe pipe;
int score = 0;


// FUNCTIONS

void Update();
void Draw();
void UpdateDrawFrame();
void CheckCollisionPlayerPipe();
void DrawScoreBox();

// - - - - - - - - - - - - - - - - - - - - - -

int main()
{
	int screenWidth = 400;
	int screenHeight = 700;
	SetTargetFPS(60);


	InitWindow(screenWidth, screenHeight, "Flappy");

	player.Start();
	pipe.Start(1.5f);

	while (!WindowShouldClose())
	{
		UpdateDrawFrame();
	}

	CloseWindow();
	return 0;
}

void UpdateDrawFrame()
{
	Update();
	Draw();
}

void Update()
{
	player.Update();
	pipe.Update();
	CheckCollisionPlayerPipe();

	if (!player.isAlive && IsKeyPressed(KEY_SPACE))
	{
		player.Start();
		pipe.Start(1.5f);
		score = 0;
	}
}
void Draw()
{
	BeginDrawing();

	ClearBackground(BLACK);

	player.Draw();
	pipe.Draw();
	DrawScoreBox();

	DrawFPS(10, 10);

	EndDrawing();
}

void CheckCollisionPlayerPipe()
{
	if (CheckCollisionRecs(player.rect, pipe.rectUp) || CheckCollisionRecs(player.rect, pipe.rectDown))
	{
		pipe.speed = 0.0f;
		player.jumpHeight = 0.0f;
		player.isAlive = false;
	}
	if (CheckCollisionRecs(player.rect, pipe.scoreRect) && !player.scored && player.isAlive)
	{
		score += 1;
		player.scored = true;
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