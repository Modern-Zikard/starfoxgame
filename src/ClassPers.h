#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ClassAnimationManager.h"


//#define GROUND 200




class Pers
{
private:

	AnimManager anim;

	float dx = 0;
	float dy = 0;
	float x;
	float y;
	float width = 40;
	float height = 45;

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
	void Collision(int dir, float TileSize, std::vector <std::string> TileMap);
	void update(float time, float TileSize, std::vector <std::string> TileMap);
	void draw(sf::RenderWindow &window);
	void AiFunck(float speed);
	
};

