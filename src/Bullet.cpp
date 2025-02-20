#include "Bullet.h"

void Bullet::update(float time, float TileSize, std::vector<std::string> TileMap)
{
	x += dx * time;
	y += dy * time;
	
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



Bullet::Bullet(AnimManager& a, float x, float y, float CurX, float CurY , bool dir)
{
	float k = 0.5;   // Коэффициент скорости пули 
	StartX = x;
	StartY = y;
	CursorX = CurX;
	CursorY = CurY;
	anim = a;
	anim.set("move");
	this->x = x;

	this->y = y;
	dx = k * (CursorX - StartX) / (fabs(CursorX - StartX)+fabs(CursorY - StartY));
	dy = k * (CursorY - StartY) / (fabs(CursorX - StartX) + fabs(CursorY - StartY));
	if (StartX == CursorX) { dy = 0; dx = k; }
	if (StartY == CursorY) { dy = k; dx = 0; }
	 

	w = h = 5;
	life = true;
}