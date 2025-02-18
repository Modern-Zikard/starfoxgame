#include "Cursor.h"


Cursor::Cursor(sf::Texture &t, float x, float y, float w, float h)
{
	sprite.setTexture(t);
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Cursor::draw(sf::RenderWindow& window)
{
	sprite.setPosition(x, y);
	window.draw(sprite);
}

void Cursor::update(float time)
{
	std::cout << "CursorUpdate" << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
	{
		std::cout << "A push" << std::endl;
		x -= 0.1 * time;
	} 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		std::cout << "W push" << std::endl;
		y -= 0.1 * time;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		std::cout << "D push" << std::endl;
		x += 0.1 * time;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		std::cout << "S push" << std::endl;
		y += 0.1 * time;
	}
	
}


