#include "Enemy.h"

Enemy::Enemy(AnimManager &a, float x, float y, bool dir)
{
	w = 32;
	h = 45;
	dx = 0.1;
	this->x = x;
	this->y = y;

	anim = a;

	this->dir = dir;
	STATE = State::stay;
}
void Enemy::Collision(int dir, float TileSize, std::vector <std::string> TileMap)
{



	for (int i = y / TileSize; i < (y + h) / TileSize; i++)
		for (int j = x / TileSize; j < (x + w) / TileSize; j++)
		{

			if (TileMap[i][j] == 'S')
			{
				if ((dx > 0) && (dir == 0)) x = j * TileSize - w;
				if ((dx < 0) && (dir == 0)) x = j * TileSize + TileSize;

				if ((dy > 0) && (dir == 1)) { y = i * TileSize - h; dy = 0; onGround = true; }
				if ((dy < 0) && (dir == 1)) { y = i * TileSize + TileSize; dy = 0; }


			}

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
