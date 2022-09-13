#include "raylib.h"
#include <iostream>

#pragma once
class GameObject {
public:
	Vector2 pos;
	Vector2 size;
	const char* tag;
	Color color;
	const char* id;

	Rectangle rect;
	Rectangle groundCollider;

	GameObject()
		: pos({ 0, 0 }), size({ 0, 0 }), tag("None") {
		std::cout << "Init no args" << std::endl;
	}
	GameObject(const char* _tag)
		: pos({ 0, 0 }), size({ 0, 0 }), tag(_tag) {
		std::cout << "Init: " << _tag << " >>> no other args" << std::endl;
	}
	GameObject(Vector2 _pos, Vector2 _size, const char* _tag, Color _color)
		: pos(_pos), size(_size), tag(_tag), color(_color), id("none") {
		rect = { pos.x, pos.y, size.x, size.y };
		std::cout << "Init: " << _tag << std::endl;
	}
	GameObject(Vector2 _pos, Vector2 _size, const char* _tag, Color _color, const char* _id)
		: pos(_pos), size(_size), tag(_tag), color(_color), id(_id) {
		rect = { pos.x, pos.y, size.x, size.y };
		std::cout << "Init: " << _tag << std::endl;
	}


	void Draw()
	{
		DrawRectangleRec(rect, color);

		DrawRectangleLinesEx(groundCollider, 1.0f, LIME);
	}
};