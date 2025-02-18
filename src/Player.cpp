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
		if (STATE == State::stay || STATE == State::walk) 
		{ 
			if (onGround)
			{
				std::cout << "OnGround = " << onGround << std::endl;
				onGround = false;
				std::cout << "Jump!, OnGround = " << onGround << std::endl;
				dy += -0.3;
				
				STATE = State::jump;
				
			}
			/*else return;*/
			
			
		}
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
		/*if(anim.getNumFrame() == 4)*/
		
		shoot = false;
	}
}

Player::Player(AnimManager &a, AnimManager &tail, float x, float y, bool dir)
{
}

void Player::Collision(int dir, float TileSize, std::vector <std::string> TileMap)
{
	
	for (int i = (y + ColldY) / TileSize; i < ((y + ColldY) + CollHei) / TileSize; i++)
		for (int j = (x + ColldX) / TileSize; j < ((x + ColldX) + CollWid) / TileSize; j++)
		{
			/*std::cout << "Collision check - TileMap[" << i << "][" << j << "]" << std::endl;*/
			if (TileMap[i][j] == '1' || TileMap[i][j] == '2')
			{
				
				if ((dx > 0) && (dir == 0)) x = (j * TileSize - CollWid) - ColldX;
				if ((dx < 0) && (dir == 0)) x = (j * TileSize + TileSize) - ColldX;

				if ((dy > 0) && (dir == 1)) { y = (i * TileSize - CollHei) - ColldY; dy = 0;}
				if ((dy < 0) && (dir == 1)) { y = (i * TileSize + TileSize) - ColldY; }
			}
			 
		}
}



void Player::update(float time, float TileSize, std::vector <std::string> TileMap)
{

	if (!dy) { onGround = true;/* ColldY = 10;*/ }
	else { onGround = false; /* ColldY = 0;*/ }

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
		if (onGround)
		{
			anim.set("shoot");
			if (STATE == State::walk) anim.set("shootrun");
		}
		else anim.set("shootjump");
	}
		
	
	if (dir) anim.flip(true);
	else anim.flip(false);

	dy += 0.0005 * time;

	y += dy * time;
	this->Collision(1, TileSize, TileMap);

	x += dx * time;
	this->Collision(0, TileSize, TileMap);

	anim.tick(time);

	key["Left"] = false;
	key["Right"] = false;
	key["Up"] = false;
	key["Down"] = false;
	key["Space"] = false;


	/*std::cout << "dy = " << dy << ", dx = " << dx << std::endl;*/
}

void Player::setNumFrame(float num) { anim.setNumFrame(num); }
int Player::getNumFrame() { return anim.getNumFrame(); }
bool Player::getDir() { return this->dir; }