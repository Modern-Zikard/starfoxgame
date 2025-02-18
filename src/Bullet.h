#pragma once

#include "Entity.h"

class Bullet : public Entity
{
private:
	float StartX;
	float StartY;
	float CursorX;
	float CursorY;
public:
	Bullet(AnimManager &a, float x, float y, bool dir);
	void update(float time, float TileSize, std::vector <std::string> TileMap);
};