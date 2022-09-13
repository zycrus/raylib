#include "raylib.h"

#include "InstanceManager.h"

// FUNCTIONS
void Update();
void Draw();
void UpdateDrawFrame();
void InitLevel();

// Initialize Instance Manager
InstanceManager instances;

void InitLevel() {
	float _screenWidth = (float)GetScreenWidth();
	float _screenHeight = (float)GetScreenHeight();

	instances.CreateGround({ 200, _screenHeight - 500 }, { 100, 20 }, GRAY, "g2");
	instances.CreateGround({ 200, _screenHeight - 200 }, { 100, 20 }, GRAY, "g2");
	instances.CreateGround({ 10, _screenHeight - 50 }, { _screenWidth - 20, 40 }, GRAY, "g1");
}

int main()
{
	const int screenWidth = 460;
	const int screenHeight = 640;

	SetTargetFPS(60);
	InitWindow(screenWidth, screenHeight, "Tower Climber");

	InitLevel();

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
	instances.Update();
}

void Draw()
{
	ClearBackground(WHITE);

	instances.Draw();

	DrawFPS(10, 10);
}