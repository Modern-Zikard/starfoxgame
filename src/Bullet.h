#pragma once

#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet(AnimManager &a, float x, float y, bool dir);
	void update(float time, float TileSize, std::vector <std::string> TileMap);
};