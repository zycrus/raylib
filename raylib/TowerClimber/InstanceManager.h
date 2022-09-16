#pragma once
#include "Ground.h"
#include "Player.h"
#include <vector>

class InstanceManager {
	std::vector<Ground*> groundArray;

public:
	Player* player;

	void CreateGround(Vector2 pos, Vector2 size, Color color)
	{
		groundArray.push_back(new Ground(pos, size, color));
		player->groundArray = groundArray;
	}

	bool IsGroundOut(Ground* ground)
	{
		if (ground->pos.y > GetScreenHeight())
		{
			return true;
		}
		return false;
	}

	void ReloadPlatform(Ground* ground)
	{
		ground->pos.y = -20;
		ground->size.y = 20;
		ground->size.x = GetRandomValue(50, 150);
		ground->pos.x = (float)GetRandomValue(0, GetScreenWidth() - ground->size.x);
	}

	void Update()
	{
		player->Update();
		player->Draw();
		for (size_t i = 0; i < groundArray.size(); ++i)
		{
			groundArray[i]->Update();
			groundArray[i]->Draw();
			if (IsGroundOut(groundArray[i]))
			{
				ReloadPlatform(groundArray[i]);
			}
		}
	}

	void Draw()
	{
		return;
	}

	void Clear()
	{
		groundArray.clear();
		delete player;
	}
};