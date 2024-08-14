#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ClassAnimationManager.h"

class Entity
{
public:
	Entity(){}
	Entity(AnimManager& a, int x, int y);

	virtual void update(float time,  float TileSize , std::vector <std::string> TileMap) = 0;
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



class Player : public Entity
{
private:
	bool shoot = false;
	bool hit = false;
	bool duck = false;
	bool onGround = true;
public:
	

	enum class State : unsigned int { stay, walk, jump, duck, swim, climb } STATE;
	std::map<std::string, bool> key;
	Player(AnimManager& a, sf::Texture& t);
	void KeyCheck();
	void update(float time, float TileSize, std::vector <std::string> TileMap);
	void Collision(int dir, float TileSize, std::vector <std::string> TileMap);
	void AiFunck(float speed);

	float getX();
	float getY();

	bool getDir();

};





