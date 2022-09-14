#pragma once
#include "GameObject.h"

class Ground : public GameObject
{
public:
	Vector2 vel;

	Ground()
		: GameObject("Ground") {}
	Ground(Vector2 pos, Vector2 size, Color color)
		: GameObject(pos, size, "Ground", color) {
		groundCollider = { pos.x + 0.01f, pos.y - 0.01f, size.x, 10.0f };
	}

	void Update()
	{
		pos.y += vel.y;
		rect = { pos.x, pos.y, size.x, size.y };
		groundCollider = { pos.x + 0.01f, pos.y - 0.01f, size.x, 10.0f };
	}

	void StartMove()
	{
		vel.y = 0.5f;
	}

	void Draw()
	{
		DrawRectangleRec(rect, color);
	}
};