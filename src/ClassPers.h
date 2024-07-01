#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ClassAnimationManager.h"


#define GROUND 200


//class Pers
//{
//private:
//
//	AnimManager body;
//	Animation tail;
//
//	float dx;
//	float dy;
//	float x;
//	float y;
//
//	bool shoot;
//	bool hit;
//
//	enum {stay, walk, jump } STATE;
//	std::map<std::string, bool> key;
//
//
//	
//
//public:
//	Pers(AnimManager &a, Animation &t);
//
//	void KeyCheck();
//
//	void update(float time);
//
//	float getDX();
//	float getDY();
//
//	sf::Sprite getSprite();
//
//	bool getOnGr();
//
//	void setDX(float x);
//	void setDY(float y);
//	void setOnGr(bool n);
//
//};