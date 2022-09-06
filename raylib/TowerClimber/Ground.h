#include "raylib.h"

#pragma once
class Ground
{
public:
	Vector2 pos = { 0, 0 };
	int width = 0;
	int height = 0;
	const char* tag = "Ground";

	Rectangle collider;

	void Start()
	{
		collider = { pos.x, pos.y, (float)width, (float)height };
	}

	void Update()
	{

	}

	void Draw()
	{
		DrawRectangleRec(collider, GRAY);
	}
};

