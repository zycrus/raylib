#include "raylib.h"
#include <iostream>

#pragma once
class GameObject {
public:
	Vector2 pos;
	Vector2 size;
	const char* tag;

	Rectangle boxCollider;

	GameObject()
		: pos({ 0, 0 }), size({ 0, 0 }), tag("None") {
		std::cout << "Init no args" << std::endl;
	}
	GameObject(const char* _tag)
		: pos({ 0, 0 }), size({ 0, 0 }), tag(_tag) {
		std::cout << "Init: " << _tag << " >>> no other args" << std::endl;
	}
	GameObject(Vector2 _pos, Vector2 _size, const char* _tag)
		: pos(_pos), size(_size), tag(_tag) {
		std::cout << "Init: " << _tag << std::endl;
	}
};