#include "Bullet.h"

void Bullet::update(float time, float TileSize, std::vector<std::string> TileMap)
{
	x += dx * time;

	for (int i = y / TileSize; i < (y + h) / TileSize; i++)
		for (int j = x / TileSize; j < (x + w) / TileSize; j++)
			if (TileMap[i][j] == 'S')
			{

				anim.set("explode");
				dx = 0;
				life = false;
			}

	anim.tick(time);
}

Bullet::Bullet(AnimManager &a, float x, float y, bool dir)
{
	anim = a;
	anim.set("move");
	this->x = x;
	this->y = y;
	dx = 0.5;
	if (dir == 1) dx = -0.5;
	w = h = 15;
	life = true;
}
