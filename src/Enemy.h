#pragma once

#include "Player.h"

class Enemy : public Player
{
public:
	Enemy(AnimManager& a, float x = 100, float y = 100, bool dir = 0);
	void update(float time, float TileSize, std::vector <std::string> TileMap);
};