#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ClassAnimationManager.h"

class Entity
{
public:
	Entity(){}
	Entity(AnimManager& a, int x, int y);

	virtual void update(float time, std::vector <std::string> TileMap) = 0;
	void draw(sf::RenderWindow& window);
	bool getLife();

	AnimManager anim;

	float dx;
	float dy;
	float x;
	float y;
	float w;
	float h;

	bool life;
	bool dir;
};

class Bull : public Entity
{
public:
	
	Bull(AnimManager a, float x, float y, bool dir);
	void update(float time, std::vector <std::string> TileMap);

private:

};





