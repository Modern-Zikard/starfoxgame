#pragma once

#include "Entity.h"
#include <cmath>

class Bullet : public Entity
{
private:
	float StartX;
	float StartY;
	float CursorX;
	float CursorY;
public:
	Bullet(AnimManager &a, float x, float y , float CurX, float CurY, bool dir);
	void update(float time, float TileSize, std::vector <std::string> TileMap);
};