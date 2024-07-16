
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ClassPers.h"

#include <iostream>

Pers::Pers(AnimManager &a, sf::Texture &t)
{
	x = 100;
	y = 100;

	anim = a;
	anim.create("walk", t, 0, 0, 42, 44, 6, 0.005, 42);
	anim.create("stay", t, 0, 44, 42, 48, 1, 0.005, 42);
	anim.create("shoot", t, 0, 92, 60, 48, 5, 0.006, 60);
	anim.create("duck", t, 0, 218, 44, 49, 1, 0.003, 44);
	anim.create("shootrun", t, 0, 267, 59, 44, 6, 0.005, 59);
	anim.create("jump", t, 0, 140, 40, 54, 1, 0.005, 40);
	
	STATE = State::stay;
}

void Pers::KeyCheck()
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
		if (STATE == State::swim || STATE == State::climb) dy = -0.05;
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
		
		shoot = false;
	}
}

void Pers::Collision(int dir, float TileSize, std::vector <std::string> TileMap)
{
	
	
	
	for (int i = y / TileSize; i < (y + height) / TileSize; i++)
		for (int j = x / TileSize; j < (x + width) / TileSize; j++)
		{
			
			if (TileMap[i][j] == 'S')
			{
				if ((dx > 0) && (dir == 0)) x = j * TileSize - width;
				if ((dx < 0) && (dir == 0)) x = j * TileSize + TileSize;

				if ((dy > 0) && (dir == 1)) { y = i * TileSize - height; dy = 0; onGround = true; }
				if ((dy < 0) && (dir == 1)) { y = i * TileSize + TileSize; dy = 0; }
			

			}
			
		}

}

void Pers::update(float time, float TileSize, std::vector <std::string> TileMap)
{
	std::cout << " Point 1 " << std::endl;
	
	KeyCheck();
	
		if (STATE == State::stay) {
			anim.set("stay"); 
			/*width = 42; height = 48;*/

		}
		if (STATE == State::walk) {
			anim.set("walk"); 
			/*width = 42; height = 44;*/
		}
		if ((STATE == State::jump )||(dy!= 0)) {
			anim.set("jump");
			std::cout << " jump " << std::endl;
			/*width = 40; height = 54;*/
		}
		if (STATE == State::duck) {
			anim.set("duck"); 
			/*width = 44; height = 49;*/
		}
		
	if (shoot) 
	{ 
		anim.set("shoot"); 

		/*width = 60; height = 48;*/

		if (STATE == State::walk) 
		{ 
			anim.set("shootrun");

			/*width = 59; height = 44;*/
		}
	}
	std::cout << " Point 4 " << std::endl;
	
	if(dir) anim.flip(true);
	
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
void Pers::draw(sf::RenderWindow &window)
{
	anim.draw(window, x, y);
}
