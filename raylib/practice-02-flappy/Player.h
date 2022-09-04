#include "raylib.h"
#include "raymath.h"

class Player
{
private:
	float gravity = 1000.0f;

	bool OnCollideGround()
	{
		return pos.y + rect.height + vSpeed * GetFrameTime() > GetScreenHeight();
	}

public:
	Vector2 pos;
	float jumpHeight = 400.0f;
	float vSpeed = 0.0f;
	Rectangle rect;
	bool scored = false;
	bool isAlive = true;

	void Start()
	{
		jumpHeight = 400.0f;
		pos = { (float)GetScreenWidth() / 3, (float)GetScreenHeight() / 3 };
		vSpeed = 0.0f;
		scored = false;
		isAlive = true;
	}

	void Update()
	{
		if (!OnCollideGround())
			pos.y += vSpeed * GetFrameTime();
			vSpeed += gravity * GetFrameTime();
			
		rect = { pos.x, pos.y, 50, 45 };

		if (isAlive && IsKeyPressed(KEY_SPACE))
		{
			Jump();
		}
	}

	void Draw()
	{
		DrawRectangleLinesEx(rect, 3.0f, BLUE);
		//DrawPolyLinesEx({rect.x + rect.width / 2, rect.y + rect.height / 2}, 3, rect.width / 2, angle, 10.0f, WHITE);
		//DrawRectanglePro(rect, {rect.width / 2, rect.height / 2}, angle, WHITE);
	}

	void Jump()
	{
		vSpeed = -jumpHeight;
	}
};
