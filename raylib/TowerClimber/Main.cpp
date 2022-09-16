#include "raylib.h"

#include "InstanceManager.h"

// FUNCTIONS
void Update();
void Draw();
void UpdateDrawFrame();
void InitLevel();
void RestartLevel();
void GeneratePlatforms(int);

// Initialize Instance Manager
InstanceManager instances;

void InitLevel() {
	float _screenWidth = (float)GetScreenWidth();
	float _screenHeight = (float)GetScreenHeight();

	instances.player = new Player({ _screenWidth / 2, _screenHeight - 82 }, { 25, 31 }, SKYBLUE);
	instances.CreateGround({ 10, _screenHeight - 50 }, { _screenWidth - 20, 40 }, GRAY);

	for (int ypos = (int)_screenHeight - 150; ypos > 0; ypos -= 100)
	{
		GeneratePlatforms(ypos);
	}
}

void RestartLevel()
{
	instances.Clear();
	InitLevel();
}

void GeneratePlatforms(int ypos)
{
	int _screenWidth = GetScreenWidth();
	int _screenHeight = GetScreenHeight();
	int width = GetRandomValue(50, 150);
	Vector2 pos = { (float)GetRandomValue(0, GetScreenWidth() - width), (float)ypos };
	instances.CreateGround(pos, { (float)width, 20 }, GRAY);
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

	instances.Clear();
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