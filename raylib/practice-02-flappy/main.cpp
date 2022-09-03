#include "raylib.h"

void Update()
{

}
void Draw()
{
	BeginDrawing();

		ClearBackground(BLACK);

		DrawFPS(10, 10);

	EndDrawing();
}
void UpdateDrawFrame()
{
	Update();
	Draw();
}

int main()
{
	int screenWidth = 500;
	int screenHeight = 700;
	SetTargetFPS(60);

	InitWindow(screenWidth, screenHeight, "Flappy");

	while (!WindowShouldClose())
	{
		UpdateDrawFrame();
	}

	CloseWindow();
	return 0;
}