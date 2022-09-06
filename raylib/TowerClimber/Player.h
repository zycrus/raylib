#include "raylib.h"

#pragma once
class Player
{
public:
	Vector2 pos = { 20, 50 };
	int width = 30;
	int height = 50;

	int direction = 0;
	int facingDirection = 1;
	float friction = 10.0f;
	float speed = 15.0f;
	float gravity = 20.0f;
	float hSpeed = 0.0f;
	float vSpeed = 0.0f;
	bool isGrounded = false;

	Rectangle collider;
	Rectangle groundCollider;
	Rectangle rightCollider;
	Rectangle leftCollider;

	void Start()
	{

	}

	void Update()
	{
		collider = { pos.x, pos.y, (float)width, (float)height };
		if (!CheckLeftCollision() && !CheckRightCollision())
		{
			if (IsKeyDown(KEY_A))
			{
				direction = -1;
				facingDirection = -1;
				if (hSpeed < speed)
					hSpeed += speed * direction * GetFrameTime();
			}
			else if (IsKeyDown(KEY_D))
			{
				direction = 1;
				facingDirection = 1;
				if (hSpeed < speed)
					hSpeed += speed * direction * GetFrameTime();
			}
			else
			{
				direction = 0;
				if (facingDirection == 1)
					if (hSpeed > 0)
						hSpeed -= friction * GetFrameTime();
					else
						hSpeed = 0;

				if (facingDirection == -1)
					if (hSpeed < 0)
						hSpeed += friction * GetFrameTime();
					else
						hSpeed = 0;
			}
		}
		else if (CheckLeftCollision())
		{
			if (hSpeed < -1)
			{
				hSpeed = hSpeed * -0.8f;
				facingDirection = 1;
			}
			else
			{
				hSpeed = 0;
				pos.x = 1;
			}
		}

		else if (CheckRightCollision())
		{
			if (hSpeed > 1)
			{
				hSpeed = hSpeed * -0.8f;
				facingDirection = -1;
			}
			else
			{
				hSpeed = 0;
				pos.x = GetScreenWidth() - width - 1;
			}
		}

		pos.x += hSpeed;

		groundCollider = { pos.x + 2, pos.y + height, (float)width - 4, 0.1f };
		leftCollider = { pos.x - 0.1f, pos.y + 2, 0.1f, (float)height - 4  };
		rightCollider = { pos.x + width, pos.y + 2, 0.1f, (float)height - 4 };

		if (!isGrounded)
		{
			vSpeed -= gravity * GetFrameTime();
		}
		else
		{
			if (IsKeyPressed(KEY_SPACE))
			{
				vSpeed = 10.0f;
				isGrounded = false;
			}
			else
			{
				vSpeed = 0;
			}
		}

		pos.y -= vSpeed;
	}

	bool CheckGroundCollision(Rectangle other)
	{
		return (CheckCollisionRecs(collider, other));
	}

	bool CheckLeftCollision()
	{
		return pos.x <= 0;
	}

	bool CheckRightCollision()
	{
		return pos.x + width >= GetScreenWidth();
	}

	void Draw()
	{
		DrawRectangleRec(collider, BLUE);
		DrawRectangleRec(groundCollider, RED);
		DrawText(TextFormat("%i", hSpeed), 10, 50, 20, GREEN);
		DrawText(TextFormat("%i", facingDirection), 10, 70, 20, GREEN);
	}
};

