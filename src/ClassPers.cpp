
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ClassPers.h"

#include <iostream>

Pers::Pers(AnimManager &a, sf::Texture &t)
{
	x = 0;
	y = 0;

	anim = a;
	anim.create("walk", t, 0, 0, 42, 44, 6, 0.005, 42);
	anim.create("stay", t, 0, 44, 42, 48, 1, 0.005, 42);
	anim.create("shoot", t, 0, 92, 60, 48, 5, 0.006, 60);
	anim.create("duck", t, 0, 218, 44, 49, 1, 0.003, 44);
	anim.create("shootrun", t, 0, 267, 59, 44, 6, 0.005, 59);
	
	STATE = State::stay;
}

void Pers::KeyCheck()
{
	//////////////ÍÀÆÀÒÈÅ ÊËÀÂÈØ///////////////////
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

	//////////////ÎÒÏÓÑÊÀÍÈÅ ÊËÀÂÈØ///////////////////
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

void Pers::update(float time)
{
	KeyCheck();

	if (STATE == State::stay) anim.set("stay");
	if (STATE == State::walk) anim.set("walk");
	if (STATE == State::jump) anim.set("jump");
	if (STATE == State::duck) anim.set("duck");

	if (shoot) 
	{ 
		anim.set("shoot"); 
		if (STATE == State::walk) anim.set("shootrun");
	}

	if(dir) anim.flip(true);
	else anim.flip(false);

	x += dx * time;
	if (!onGround) dy += 0.0005 * time;

	dy += 0.0005 * time;
	y += dy * time;
	onGround = false;

	if (y > GROUND) { y = GROUND; dy = 0; onGround = true; }
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

