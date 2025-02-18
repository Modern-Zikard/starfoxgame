#include "Bullet.h"

void Bullet::update(float time, float TileSize, std::vector<std::string> TileMap)
{
	x += dx * time;
	

	for (int i = y / TileSize; i < (y + h) / TileSize; i++)
		for (int j = x / TileSize; j < (x + w) / TileSize; j++)
			if ((TileMap[i][j] == '1') || (TileMap[i][j] == '2'))
			{
				
				anim.set("explode");//x-3 y-4
				if(dir == 0)
				{
					x -= 4;
					y -= 4;
				}
				dx = 0;
				std::cout << std::endl << "anim.getNumFrame() = " << anim.getNumFrame() << std::endl;

			}
	std::cout << std::endl << "bullet x = " << x << std::endl << "bullet y = " << y << std::endl;
	if(anim.getNumFrame()== 4)
	{
		life = false;
		std::cout << std::endl << " bullet is gone!" << std::endl;
	}
		
	anim.tick(time);
	
}



Bullet::Bullet(AnimManager &a, float x, float y, bool dir)
{
	anim = a;
	anim.set("move");
	this->x = x;

	this->y = y;
	dx = 0.2;
	if (dir == 1) dx = -0.2;
	w = h = 5;
	life = true;
}