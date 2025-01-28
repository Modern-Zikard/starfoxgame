#pragma once

#include "Entity.h"



class Player : public Entity
{
protected:

	
	enum class State : unsigned int { stay, walk, jump, duck, swim, climb } STATE;
	bool shoot = false;
	bool hit = false;
	bool duck = false;
	bool onGround = true;

	float ColldX = 18;
	float ColldY = 10;					// Collision coordinate 
	float CollWid = 24;					// Collision Rect width
	float CollHei = 42;					// Collision Rect height

public:

	Player(){}
	
	Player(AnimManager &a, float x, float y, bool dir = 0);

	Player(AnimManager &a, AnimManager &tail, float x, float y, bool dir = 0);

	std::map<std::string, bool> key;
	void KeyCheck();
	void update(float time, float TileSize, std::vector <std::string> TileMap);
	void Collision(int dir, float TileSize, std::vector <std::string> TileMap);
	void getNumFrame(float num);
	int getNumFrame();
	bool getDir();
};