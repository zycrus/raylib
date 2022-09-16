#include <iostream>
#include <vector>

#include "raylib.h"

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 300
#define FRAME_SPEED 10

class Sprite {
public:
	Texture2D image;

	int frameWidth;
	int frameHeight;

	// Source Rectangle
	Rectangle sourceRect;
	
	// Destination Rectangle
	Rectangle destRect;

	// Origin relative to destination rectangle
	Vector2 origin;

	const char* keyAction = "";
	const char* keyText = "";

	// Sprite Rotation
	int rotation = 0;

	// Animation
	int animFrame = 0;
	int currentFrame = 2;

	int framesCounter = 0;
	int framesSpeed = 4;

	// Initialize Sprite
	Sprite(const char* dest) : 
		image(LoadTexture(dest)),
		frameWidth(image.width/4),
		frameHeight(image.height/4),
		sourceRect({ 0.0f, 0.0f, (float)frameWidth, (float)frameHeight }),
		destRect({ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, frameWidth * 4.0f, frameHeight * 4.0f }),
		origin({ (float)frameWidth * 2.0f, (float)frameHeight * 2.0f })
	{	}

	void Update()
	{
		//rotation++;
		Animate();

		if (IsKeyPressed(KEY_S))
		{
			keyAction = "Pressed: ";
			keyText = "S";
			sourceRect.y = (float)frameHeight * 0;
			animFrame = 2;
			currentFrame = animFrame;
		}
		if (IsKeyPressed(KEY_W))
		{
			keyAction = "Pressed: ";
			keyText = "W";
			sourceRect.y = (float)frameHeight * 1;
			animFrame = 2;
			currentFrame = animFrame;
		}
		if (IsKeyPressed(KEY_A))
		{
			keyAction = "Pressed: ";
			keyText = "A";
			sourceRect.y = (float)frameHeight * 2;
			animFrame = 2;
			currentFrame = animFrame;
		}
		if (IsKeyPressed(KEY_D))
		{
			keyAction = "Pressed: ";
			keyText = "D";
			sourceRect.y = (float)frameHeight * 3;
			animFrame = 2;
			currentFrame = animFrame;
		}
		if (IsKeyReleased(KEY_S) || IsKeyReleased(KEY_W) || IsKeyReleased(KEY_A) || IsKeyReleased(KEY_D))
		{
			keyAction = "Released: ";
			animFrame = 0;
			currentFrame = animFrame;
			framesSpeed = 3;
		}
	}

	void Draw()
	{
		DrawTexturePro(image, sourceRect, destRect, origin, (float)rotation, WHITE);
		int keyActWidth = MeasureText(keyAction, 10);
		int keyTextWidth = MeasureText(keyText, 10);
		DrawText(keyAction, GetScreenWidth() - keyActWidth - keyTextWidth - 10, 10, 10, SKYBLUE);
		DrawText(keyText, GetScreenWidth() - keyTextWidth - 10, 10, 10, SKYBLUE);
	}

	void UnloadImages()
	{
		UnloadTexture(image);
	}

	void Animate()
	{
		framesCounter++;

		if (framesCounter >= (60 / framesSpeed))
		{
			framesCounter = 0;
			currentFrame++;

			if (currentFrame > animFrame + 1) currentFrame = animFrame;

			sourceRect.x = (float)currentFrame * (float)frameWidth;
		}
	}
};

// Main Game Loop
int main()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sprite Loading Test");
	SetTargetFPS(60);
	Sprite character = Sprite("Sprites/Basic Charakter Spritesheet.png");
	
	while (!WindowShouldClose())
	{
		// Update variables
		character.Update();

		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		character.Draw();
		DrawText(TextFormat("Frame: %i", character.currentFrame), 10, 10, 10, LIME);


		const char* credits = "https://cupnooble.itch.io";
		int textWidth = MeasureText(credits, 10);
		DrawText(credits, GetScreenWidth() - 10 - textWidth, GetScreenHeight() - 20, 10, LIGHTGRAY);

		EndDrawing();
	}

	character.UnloadImages();
	CloseWindow();
}