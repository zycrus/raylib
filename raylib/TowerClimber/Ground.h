#include "GameObject.h"

class Ground : public GameObject
{
public:
	Ground()
		: GameObject("Ground") {}
	Ground(Vector2 pos, Vector2 size)
		: GameObject(pos, size, "Ground") {}
};