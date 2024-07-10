#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ClassAnimationManager.h"


#define GROUND 200




class Pers
{
private:

	AnimManager anim;

	float dx = 0;
	float dy = 0;
	float x;
	float y;


	bool dir = false;
	bool shoot = false;
	bool hit = false;
	bool duck = false;
	bool onGround = true;

public:

	enum class State : unsigned int { stay, walk, jump, duck, swim, climb } STATE;
	std::map<std::string, bool> key;

	Pers(AnimManager &a, sf::Texture &t);
	void KeyCheck();
	void update(float time);
	void draw(sf::RenderWindow &window);
};

