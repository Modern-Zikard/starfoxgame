
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ClassPers.h"

#include <iostream>

Pers::Pers(AnimManager &a)
{
	this->x = 50;
	this->y = 50;
	this->anim = a;
	STATE = State::stay;
}

void Pers::KeyCheck()
{
	//////////////Õ¿∆¿“»≈  À¿¬»ÿ///////////////////
	if (key["L"])
	{
		dir = true;
		if (STATE != State::duck) dx = -0.1;
		if (STATE == State::stay) STATE = State::walk;
	}
	if (key["R"])
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
	if (!(key["R"] || key["L"]))
	{
		std::cout << "R or L" << std::endl;
		dx = 0;
		if (STATE == State::walk) STATE = State::stay;
	}
	if (!(key["Up"] || key["Down"]))
	{
		std::cout << "Up or Down" << std::endl;
		if (STATE == State::swim || STATE == State::climb) dy = 0;
	}
	if (!key["Down"])
	{
		std::cout << "Down" << std::endl;
		if (STATE == State::duck) { STATE = State::stay; }
	}
	if (!key["Space"])
	{
		std::cout << "Space" << std::endl;
		shoot = false;
	}
}

void Pers::update(float time)
{
	this->KeyCheck();

	if (STATE == State::stay) anim.set("stay");
	if (STATE == State::walk) anim.set("walk");
	if (STATE == State::jump) anim.set("jump");
	if (STATE == State::duck) anim.set("duck");

	if (shoot) { anim.set("shoot"); }

	if (dir) anim.flip(true);
	x += dx * time;
	if (!onGround) dy += 0.0005 * time;

	dy += 0.0005 * time;
	y += dy * time;
	onGround = false;

	if (y > GROUND) { y = GROUND; dy = 0; onGround = true; }
	anim.tick(time);

	key["L"] = key["R"] = key["Up"] = key["Down"] = key["Space"] = false;
}

