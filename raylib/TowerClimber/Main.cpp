#include "raylib.h"

#include "Player.h"
#include "Ground.h"

// FUNCTIONS
void Update(void);
void Draw(void);
void UpdateDrawFrame(void);

// OBJECTS
Player player;
Ground ground;
Ground ground2;

int main()
{
	const int screenWidth = 460;
	const int screenHeight = 640;

	SetTargetFPS(60);
	InitWindow(screenWidth, screenHeight, "Tower Climber");

	player.pos = { screenWidth/2, screenHeight / 2 };
	ground.pos = { 20, screenHeight - 100 };
	ground.width = 420;
	ground.height = 50;
	ground.Start();
	ground2.pos = { 50, screenHeight - 150 };
	ground2.width = 50;
	ground2.height = 20;
	ground2.Start();

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

	BeginDrawing();
	Draw();
	EndDrawing();
}

void Update()
{
	player.Update();
	if (player.CheckGroundCollision(ground.collider))
	{
		player.isGrounded = true;
		player.pos.y = ground.pos.y - player.height;
	}
}

void Draw()
{
	ClearBackground(WHITE);

	int _screenWidth = GetScreenWidth();
	int _screenHeight = GetScreenHeight();
	int centerX = _screenWidth / 2;
	int centerY = _screenHeight / 2;

	player.Draw();
	ground.Draw();
	ground2.Draw();

	DrawFPS(10, 10);
}