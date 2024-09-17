#include "Player.h"

Player::Player(AnimManager &a, float x, float y, bool dir)
{
	w = 60;
	h = 52;
	this->x = x;
	this->y = y;
	anim = a;
	this->dir = dir;
	STATE = State::stay;
}

void Player::KeyCheck()
{
	//////////////Õ¿∆¿“»≈  À¿¬»ÿ///////////////////
	if (key["Left"])
	{
		dir = true;
		if (STATE != State::duck) dx = -0.1;
		if (STATE == State::stay) STATE = State::walk;
	}
	if (key["Right"])
	{
		dir = false;
		if (STATE != State::duck) dx = 0.1;
		if (STATE == State::stay) STATE = State::walk;
	}
	if (key["Up"])
	{
		if (STATE == State::stay || STATE == State::walk) { dy = -0.27; STATE = State::jump; }
		/*if (STATE == State::swim || STATE == State::climb) dy = -0.05;*/
	}
	if (key["Down"])
	{
		if (STATE == State::stay || STATE == State::walk) { STATE = State::duck; dx = 0; }
		if (STATE == State::swim || STATE == State::climb) dy = 0.05;
	}
	if (key["Space"])
	{
		shoot = true;
		anim.setNumFrame(0);
	}
	//////////////Œ“œ”— ¿Õ»≈  À¿¬»ÿ///////////////////
	if (!(key["Right"] || key["Left"]))
	{
		dx = 0;
		if (STATE == State::walk) STATE = State::stay;
	}
	if (!(key["Up"] || key["Down"]))
	{
		if (STATE == State::swim || STATE == State::climb) dy = 0;
	}

	if (!key["Down"])
	{
		if (STATE == State::duck) { STATE = State::stay; }
	}
	if (!key["Space"])
	{
		if(anim.getNumFrame() == 4)
			shoot = false;
	}
}

void Player::Collision(int dir, float TileSize, std::vector <std::string> TileMap)
{
	sx = x + 18;
	sy = y + 10;

	for (int i = sy / TileSize; i < (sy + sh) / TileSize; i++)
		for (int j = sx / TileSize; j < (sx + sw) / TileSize; j++)
		{
			/*std::cout << "Collision check - TileMap[" << i << "][" << j << "]" << std::endl;*/
			if (TileMap[i][j] == 'S')
			{
				if ((dx > 0) && (dir == 0)) sx = j * TileSize - sw;
				if ((dx < 0) && (dir == 0)) sx = j * TileSize + TileSize;

				if ((dy > 0) && (dir == 1)) { sy = i * TileSize - sh; dy = 0; /*onGround = true;*/ }
				if ((dy < 0) && (dir == 1)) { sy = i * TileSize + TileSize; dy = 0; }
			}
			x = sx - 18;
			y = sy - 10; 
		}
}



void Player::update(float time, float TileSize, std::vector <std::string> TileMap)
{
	STATE = State::stay;
	KeyCheck();

	if (STATE == State::stay) {
		anim.set("stay");
	}
	if (STATE == State::walk) {
		anim.set("walk");
	}
	if ((STATE == State::jump) || (dy != 0)) {
		anim.set("jump");
	}
	if (STATE == State::duck) {
		anim.set("duck");
	}

	if (shoot)
	{
		anim.set("shoot");
		if (STATE == State::walk)
		{
			anim.set("shootrun");
		}
	}
	std::cout << "sx = " << sx << ", sy = " << sy << std::endl; 
	if (dir) anim.flip(true);
	else anim.flip(false);

	x += dx * time;

	this->Collision(0, TileSize, TileMap);

	dy += 0.0005 * time;
	y += dy * time;

	this->Collision(1, TileSize, TileMap);

	anim.tick(time);

	key["Left"] = false;
	key["Right"] = false;
	key["Up"] = false;
	key["Down"] = false;
	key["Space"] = false;
}

void Player::getNumFrame(float num) { anim.setNumFrame(num); }
int Player::getNumFrame() { return anim.getNumFrame(); }
bool Player::getDir() { return this->dir; }