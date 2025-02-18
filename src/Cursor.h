
#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ClassAnimationManager.h"

class Cursor 
{
private:
	float x;
	float y;
	float w;
	float h;
	sf::Sprite sprite;


public:

	Cursor() {}
	Cursor(sf::Texture &t, float x, float y, float w, float h);


	/*void KeyCheck();*/
	void update(float time);
	void draw(sf::RenderWindow& window);

	

};