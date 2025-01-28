#include "Entity.h"

Entity::Entity(AnimManager &a, float x, float y, bool dir)
{	
	anim = a;
	this->x = x;
	this->y = y;
	this->dir = dir;
	this->life = true;
	dx = dy = 0;
}

Entity::Entity(AnimManager &a, AnimManager &t, AnimManager &e, float x, float y, bool dir)
{
	
	anim = a;
	TailAnim = t;
	EyesAnim = e;
	this->x = x;
	this->y = y;
	this->dir = dir;
	this->life = true;
	dx = dy = 0;
}

void Entity::draw(sf::RenderWindow &window) { anim.draw(window, x, y);}
bool Entity::getLife() {return this->life;}
float Entity::getX() { return this->x; }
float Entity::getY() { return this->y; }