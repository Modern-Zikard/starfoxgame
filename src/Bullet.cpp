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
	float mx = 1;
	float my = 1;
	StartX = x;
	StartY = y;
	CursorX = CurX;
	CursorY = CurY;
	anim = a;
	anim.set("move");
	this->x = x;

	this->y = y;
	float VecX = CursorX - StartX;
	float VecY = CursorY - StartY;
	if (VecX < 0)
		mx = -1;
	if (VecY < 0)
		my = -1;
	dx = k * mx * sqrt(fabs(VecX) * fabs(VecX)) / sqrt(fabs(VecX)* fabs(VecX) + fabs(VecY)* fabs(VecY));
	dy =  k * my * sqrt(fabs(VecY) * fabs(VecY)) / sqrt(fabs(VecX) * fabs(VecX) + fabs(VecY) * fabs(VecY));
	if (StartX == CursorX) { dy = 0; dx = k; }
	if (StartY == CursorY) { dy = k; dx = 0; }
	

	w = h = 5;
	life = true;
}