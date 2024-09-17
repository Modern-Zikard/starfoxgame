#include "Enemy.h"

Enemy::Enemy(AnimManager &a, float x, float y, bool dir)
{
	w = 60;
	h = 52;
	dx = 0.1;
	this->x = x;
	this->y = y;
	this->anim = a;
	this->dir = dir;
	STATE = State::stay;
}

void Enemy::update(float time, float TileSize, std::vector<std::string> TileMap)
{
	STATE = State::stay;

	if ((dx == 0) && (dy == 0)) {
		State::stay;
		anim.set("stay");
	}
	if ((dx != 0) && (dy == 0)) {

		STATE = State::walk;
		anim.set("walk");
	}
	if ((TileMap[y / TileSize + 1][x / TileSize + 1] == 'S') || (TileMap[y / TileSize - 1][x / TileSize - 1] == 'S'))
	{
		dx *= -1;
		if (dir) dir = 0;
		else dir = 1;
	}

	if (dir) anim.flip(true);
	else anim.flip(false);

	x += dx * time;

	this->Collision(0, TileSize, TileMap);

	dy += 0.0005 * time;
	y += dy * time;

	this->Collision(1, TileSize, TileMap);

	anim.tick(time);
}