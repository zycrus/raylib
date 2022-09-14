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

	void Update()
	{
		player->Update();
		for (size_t i = 0; i < groundArray.size(); ++i)
		{
			groundArray[i]->Update();
		}
	}

	void Draw()
	{
		for (size_t i = 0; i < groundArray.size(); ++i)
		{
			groundArray[i]->Draw();
		}
		player->Draw();
	}

	void Clear()
	{
		groundArray.clear();
		delete player;
	}
};