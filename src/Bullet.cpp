#include "Bullet.h"

void Bullet::update(float time, float TileSize, std::vector<std::string> TileMap)
{
	x += dx * time;

	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j < (x + w) / 32; j++)
			if (TileMap[i][j] == 'S')
			{

				anim.set("explode");
				dx = 0;
				life = false;
			}

	anim.tick(time);
}

Bullet::Bullet(AnimManager a, float x, float y, bool dir)
{
	anim = a;
	anim.set("move");
	this->x = x;
	this->y = y;
	dx = 0.1;
	if (dir == 1) dx = -0.1;
	w = h = 6;
	life = true;
}
