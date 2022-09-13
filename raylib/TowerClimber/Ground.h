#include "GameObject.h"

class Ground : public GameObject
{
public:
	Ground()
		: GameObject("Ground") {}
	Ground(Vector2 pos, Vector2 size, Color color)
		: GameObject(pos, size, "Ground", color) {}
	Ground(Vector2 pos, Vector2 size, Color color, const char* id)
		: GameObject(pos, size, "Ground", color, id) {}

	void Update()
	{
		rect = { pos.x, pos.y, size.x, size.y };
	}
};