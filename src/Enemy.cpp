#include "Enemy.h"

Enemy::Enemy(AnimManager &a, float x, float y, bool dir)
{
	w = 60;
	h = 52;
	dx = 0.1;
	this->x = x;
	this->y = y;

	anim = a;

	this->dir = dir;
	STATE = State::stay;
}
void Enemy::Collision(int dir, float TileSize, std::vector <std::string> TileMap)
{
	sx = x + 18;
	sy = y + 10;


	for (int i = sy / TileSize; i < (sy + sh) / TileSize; i++)
		for (int j = sx / TileSize; j < (sx + sw) / TileSize; j++)
		{

			if (TileMap[i][j] == 'S')
			{
				if ((dx > 0) && (dir == 0)) sx = j * TileSize - sw;
				if ((dx < 0) && (dir == 0)) sx = j * TileSize + TileSize;

				if ((dy > 0) && (dir == 1)) { sy = i * TileSize - sh; dy = 0; onGround = true; }
				if ((dy < 0) && (dir == 1)) { sy = i * TileSize + TileSize; dy = 0; }


			}
			x = sx - 18;
			y = sy - 10;
		}

}

void Enemy::update(float time, float TileSize, std::vector <std::string> TileMap)
{
	

	STATE = State::stay;
	


	if ((dx == 0)&&(dy == 0)) {
		State::stay;
		anim.set("stay");
		/*width = 42; height = 48;*/

	}
	if ((dx != 0) && (dy == 0)) {
	
		STATE = State::walk;
		anim.set("walk");
		/*width = 42; height = 44;*/
	}
	if((TileMap[y/TileSize+ 1][x/TileSize+ 1]== 'S')|| (TileMap[y / TileSize - 1][x / TileSize - 1] == 'S'))
	{
		
		dx *= -1;
		if (dir) dir = 0;
		else dir = 1;
	}
	
	
		
	
	//if (shoot)
	//{
	//	anim.set("shoot");

	//	/*width = 60; height = 48;*/

	//	if (STATE == State::walk)
	//	{
	//		anim.set("shootrun");

	//		/*width = 59; height = 44;*/
	//	}
	//}


	if (dir) anim.flip(true);

	else anim.flip(false);

	x += dx * time;



	this->Collision(0, TileSize, TileMap);



	dy += 0.0005 * time;

	y += dy * time;

	this->Collision(1, TileSize, TileMap);


	anim.tick(time);

	
}

float Enemy::getX()
{
	return this->x;
}
float Enemy::getY()
{
	return this->y;
}
bool Enemy::getDir()
{
	return this->dir;
}
