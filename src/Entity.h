#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ClassAnimationManager.h"

class Entity
{
protected:
	AnimManager anim;

	float dx = 0;
	float dy = 0;
	float x = 0;
	float y = 0;
	float w;
	float h;

	bool life;
	bool dir;
	
public:
	Entity(){}
	Entity(AnimManager &a, float x, float y, bool dir);

	virtual void update(float time,  float TileSize , std::vector <std::string> TileMap) = 0;
	void draw(sf::RenderWindow &window);
	bool getLife();

	float getX();
	float getY();
};