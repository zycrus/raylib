#include "Ground.h"
#include "Player.h"
#include <vector>

#pragma once

class InstanceManager {
	std::vector<Ground*> ground_array;

public:
	Player* player = new Player({ 100, 100 }, { 25, 31 }, SKYBLUE);

	void CreateGround(Vector2 pos, Vector2 size, Color color, const char* id)
	{
		ground_array.push_back(new Ground(pos, size, color, id));
	}

	void Update()
	{
		player->Update();
		for (size_t i = 0; i < ground_array.size(); ++i)
		{
			ground_array[i]->Update();
			player->CheckCollision(ground_array[i]);
		}
	}

	void Draw()
	{
		for (size_t i = 0; i < ground_array.size(); ++i)
		{
			ground_array[i]->Draw();
		}
		player->Draw();
	}

	void Clear()
	{
		ground_array.clear();
		delete player;
	}
};