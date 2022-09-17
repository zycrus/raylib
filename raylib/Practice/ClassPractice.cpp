#include <iostream>
#include <vector>

#include "raylib.h"

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 300
#define FRAME_SPEED 10

class Animation
{
private:
	std::vector<Texture2D> frames;
	std::vector<int> frameDelay;
	int frameTimer;
	bool isLooping;

public:
	int currentFrame;
	Animation() :
		currentFrame(0), isLooping(false), frameTimer(0)
	{}

	void UpdateFrames()
	{
		// Check if frameTimer < frameDelay[currentFrame]
		if (frameTimer < frameDelay[currentFrame])
		{
			frameTimer++;
		}
		else
		{
			frameTimer = 0;
			// Check if currentFrame < frames.size()
			if (currentFrame < (int)frames.size() - 1)
			{
				currentFrame++;
			}
			else currentFrame = 0;
		}
	}

	// Add a frame to the animation
	void AddFrame(const char* imgDest, int delay)
	{
		frames.push_back(LoadTexture(imgDest));
		frameDelay.push_back(delay);
	}

	int GetAnimLength()
	{
		return (int)frames.size();
	}

	Texture2D GetCurrentFrame()
	{
		return frames[currentFrame];
	}

	// Unload images
	void UnloadImages()
	{
		for (size_t i = 0; i < frames.size(); i++)
		{
			UnloadTexture(frames[i]);
		}
	}
};

class Sprite {
public:
	Texture2D img;

	int frameWidth;
	int frameHeight;

	// Source Rectangle
	Rectangle sourceRect;
	
	// Destination Rectangle
	Rectangle destRect;

	// Origin relative to destination rectangle
	Vector2 origin;

	// Animation Class Test
	Animation anim;

	const char* keyAction = "";
	const char* keyText = "";

	// Sprite Rotation
	int rotation = 0;

	// Initialize Sprite
	Sprite(const char* dest) : 
		img(LoadTexture(dest)),
		frameWidth(img.width),
		frameHeight(img.height),
		sourceRect({ 0.0f, 0.0f, (float)frameWidth, (float)frameHeight }),
		destRect({ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, frameWidth * 4.0f, frameHeight * 4.0f }),
		origin({ (float)frameWidth * 2.0f, (float)frameHeight * 2.0f })
	{	
		// Add the Animation Frames
		anim.AddFrame("Sprites/frames/30.png", 15);
		anim.AddFrame("Sprites/frames/31.png", 10);
	}

	void Update()
	{
		anim.UpdateFrames();
		// Check if animation length is grater than zero
		if (anim.GetAnimLength() > 0)
		{
			img = anim.GetCurrentFrame();
			frameWidth = img.width;
			frameHeight = img.height;
			sourceRect = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };
			destRect = { SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, frameWidth * 4.0f, frameHeight * 4.0f };
			origin = { (float)frameWidth * 2.0f, (float)frameHeight * 2.0f };
		}
	}

	void Draw()
	{
		DrawTexturePro(img, sourceRect, destRect, origin, (float)rotation, WHITE);
		int keyActWidth = MeasureText(keyAction, 10);
		int keyTextWidth = MeasureText(keyText, 10);
		DrawText(keyAction, GetScreenWidth() - keyActWidth - keyTextWidth - 10, 10, 10, SKYBLUE);
		DrawText(keyText, GetScreenWidth() - keyTextWidth - 10, 10, 10, SKYBLUE);
	}

	void UnloadImages()
	{
		UnloadTexture(img);
		anim.UnloadImages();
	}
};

// Main Game Loop
int main()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sprite Loading Test");
	SetTargetFPS(60);
	Sprite character = Sprite("Sprites/frames/front_idle_0.png");
	
	while (!WindowShouldClose())
	{
		// Update variables
		character.Update();

		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		character.Draw();
		DrawText(TextFormat("Frame: %i", character.anim.GetAnimLength()), 10, 10, 10, LIME);


		const char* credits = "https://cupnooble.itch.io";
		int textWidth = MeasureText(credits, 10);
		DrawText(credits, GetScreenWidth() - 10 - textWidth, GetScreenHeight() - 20, 10, LIGHTGRAY);

		EndDrawing();
	}

	character.UnloadImages();
	CloseWindow();
}