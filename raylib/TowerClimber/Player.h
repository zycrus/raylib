#pragma once
#include "GameObject.h"
#include "Ground.h"
#include <vector>

class Player : public GameObject
{
private:
	float gravity = 9.8f;
	float speed = 10.0f;
	float jumpHeight = 8.0f;
	bool gameStarted = false;

public:
	Vector2 vel;
	bool isGrounded = false;
	float direction = 1.0f;
	std::vector<Ground*> groundArray;

	Player()
		: GameObject("Player") {}
	Player(Vector2 pos, Vector2 size, Color color)
		: GameObject(pos, size, "Player", color) {
		groundCollider = { pos.x + 0.01f, pos.y + size.y, size.x - 0.02f, 1.0f };
	}

	void CopyGroundArray(std::vector<Ground*> _groundArray)
	{
		groundArray = _groundArray;
	}

	void Update()
	{
		if (!IsCollidingWithGround())
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
		if (IsKeyDown(KEY_SPACE) && IsCollidingWithGround())
		{
			if (!gameStarted)
			{
				for (size_t i = 0; i < groundArray.size(); ++i)
				{
					groundArray[i]->StartMove();
					gameStarted = true;
				}
			}
			vel.y = -jumpHeight;
		}
	}

	bool IsCollidingWithGround()
	{
		for (size_t i = 0; i < groundArray.size(); ++i)
		{
			if (CheckCollisionRecs(groundCollider, groundArray[i]->groundCollider))
			{
				if (groundArray[i]->tag == "Ground")
				{
					if (vel.y > 0.0f)
					{
						vel.y = groundArray[i]->vel.y;
						pos.y = groundArray[i]->rect.y - size.y;
						return true;
					}
				}
			}
		}
		return false;
	}
};

