class Pipe
{
public:
	Vector2 pos;
	Rectangle rectUp;
	Rectangle rectDown;
	Rectangle scoreRect;
	float speed;

	Vector2 size = { 75, 800 };

	void Start(float offset = 1.0f)
	{
		speed = 5.0f;
		pos = { (float)GetScreenWidth() * offset, (float)GetRandomValue(GetScreenHeight() / 4, GetScreenHeight() * 3 / 4)};
	}

	void Update()
	{
		scoreRect = { pos.x, pos.y - 50, size.x, 100 };
		rectDown = { pos.x, pos.y + 75, size.x, size.y };
		rectUp = { pos.x, pos.y - 875, size.x, size.y };

		pos.x -= speed;

		if (pos.x + size.x < 0)
			Start();
	}

	void Draw()
	{
		DrawRectangleRec(rectUp, BLACK);
		DrawRectangleLinesEx(rectUp, 5.0f, WHITE);
		DrawRectangleRec(rectDown, BLACK);
		DrawRectangleLinesEx(rectDown, 5.0f, WHITE);
		//DrawRectangleRec(scoreRect, GREEN);
		//DrawLine((int)pos.x, (int)rectUp.y + (int)rectUp.height, (int)pos.x, (int)rectDown.y, GREEN);
	} 
};