#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


#define GROUND 200


class Pers
{
private:

	
	float dx;
	float dy;
	float currentFrame;

	bool onGround;

	sf::FloatRect rect;
	sf::Sprite sprite;

public:
	Pers(sf::Texture& image);

	void update(float time);

	float getDX();
	float getDY();

	sf::Sprite getSprite();

	bool getOnGr();

	void setDX(float x);
	void setDY(float y);
	void setOnGr(bool n);

};