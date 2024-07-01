
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ClassPers.h"



//Pers::Pers(AnimManager &b, Animation &t)
//{
//	body = b;
//	tail = t;
//	STATE = stay;
//}
//
//void Pers::KeyCheck()
//{
//
//}

//float Pers::getDX() { return dx; }
//float Pers::getDY() { return dy; }
//
//bool Pers::getOnGr() { return onGround; }
//
//sf::Sprite Pers::getSprite() { return sprite; }
//
//void Pers::setDX(float x) { dx = x; }
//void Pers::setDY(float y) { dy = y; }
//void Pers::setOnGr(bool n) { onGround = n; }
//
//void Pers::update(float time)
//{
//	rect.left += dx * time;
//	if (!onGround) dy += 0.0005 * time;
//
//	rect.top += dy * time;
//	onGround = false;
//
//	if (rect.top > GROUND) { rect.top = GROUND; dy = 0; onGround = true; }
//
//	currentFrame += 0.005 * time;
//	if (currentFrame > 6) currentFrame -= 6;
//
//	if (dx > 0) sprite.setTextureRect(sf::IntRect(42 * int(currentFrame), 0, 42, 44));
//	if (dx < 0) sprite.setTextureRect(sf::IntRect(42 * int(currentFrame)+40, 0, -42, 44));
//	sprite.setPosition(rect.left, rect.top);
//	dx = 0;
//}