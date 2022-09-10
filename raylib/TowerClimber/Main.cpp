#include "raylib.h"
#include "Ground.h"

// FUNCTIONS
void Update(void);
void Draw(void);
void UpdateDrawFrame(void);

int main()
{
	const int screenWidth = 460;
	const int screenHeight = 640;

	SetTargetFPS(60);
	InitWindow(screenWidth, screenHeight, "Tower Climber");

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
}

void Draw()
{
	ClearBackground(WHITE);

	int _screenWidth = GetScreenWidth();
	int _screenHeight = GetScreenHeight();
	int centerX = _screenWidth / 2;
	int centerY = _screenHeight / 2;

	DrawFPS(10, 10);
}