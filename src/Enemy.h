#pragma once

#include "Entity.h"

class Enemy : public Entity
{
private:
	bool shoot = false;
	bool hit = false;
	bool duck = false;
	bool onGround = true;
	float sx;
	float sy;
	float sw = 24;
	float sh = 42;
public:


	enum class State : unsigned int { stay, walk, jump, duck, swim, climb } STATE;
	Enemy(AnimManager &a, float x = 100, float y = 100, bool dir = 0);
	void update(float time, float TileSize, std::vector <std::string> TileMap);
	void Collision(int dir, float TileSize, std::vector <std::string> TileMap);

	float getX();
	float getY();

	bool getDir();

};