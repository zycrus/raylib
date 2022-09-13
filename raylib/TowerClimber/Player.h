#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
	float gravity = 9.8f;
	float speed = 10.0f;
	float jumpHeight = 8.0f;

public:
	Vector2 vel;
	bool isGrounded = false;
	float direction = 1.0f;

	Player()
		: GameObject("Player") {}
	Player(Vector2 pos, Vector2 size, Color color)
		: GameObject(pos, size, "Player", color) {
		groundCollider = { pos.x + 0.01f, pos.y + size.y, size.x - 0.02f, 1.0f };
	}

	void Update()
	{
		if (!isGrounded)
		{
			vel.y += gravity * GetFrameTime();
		}
		else
		{
			vel.y = 0;
		}

		MoveHorizontal();
		Jump();

		pos.x += vel.x;
		pos.y += vel.y;
		groundCollider.x = pos.x - 0.01f;
		groundCollider.y = pos.y + size.y;
		rect = { pos.x, pos.y, size.x, size.y };
	}

	void MoveHorizontal()
	{
		if (pos.x < GetScreenWidth() - size.x)
		{
			if (IsKeyDown(KEY_D))
			{
				direction = 1.0f;
				if (vel.x > -speed)
				{
					vel.x += speed * direction * GetFrameTime();
				}
				else
				{
					vel.x = speed;
				}
			}
		}
		else
		{
			vel.x = 0.0f;
			pos.x = GetScreenWidth() - size.x;
		}
		if (pos.x > 0)
		{
			if (IsKeyDown(KEY_A))
			{
				direction = -1.0f;
				if (vel.x < speed)
				{
					vel.x += speed * direction * GetFrameTime();
				}
				else
				{
					vel.x = speed;
				}
			}
		}
		else
		{
			vel.x = 0.0f;
			pos.x = 0.1f;
		}
		if (!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D))
		{
			if (direction == 1.0f)
			{
				if (vel.x > 0)
				{
					vel.x -= speed * direction * GetFrameTime();
				}
				else
				{
					vel.x = 0;
				}
			}
			if (direction == -1.0f)
			{
				if (vel.x < 0)
				{
					vel.x -= speed * direction * GetFrameTime();
				}
				else
				{
					vel.x = 0;
				}
			}
		}
	}

	void Jump()
	{
		if (IsKeyDown(KEY_SPACE) && isGrounded)
		{
			vel.y = -jumpHeight;
			isGrounded = false;
		}
	}

	void CheckCollision(GameObject* other)
	{
		if (CheckCollisionRecs(groundCollider, other->rect))
		{
			if (other->tag == "Ground")
			{
				isGrounded = true;
				vel.y = 0;
				pos.y = other->rect.y - size.y;
			}
		}
		else
		{
			isGrounded = false;
		}
	}
};

