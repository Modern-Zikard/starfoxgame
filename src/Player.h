#include "Entity.h"

class Player : public Entity
{
protected:
	bool shoot = false;
	bool hit = false;
	bool duck = false;
	bool onGround = true;
	float sx;
	float sy;
	float sw = 24;
	float sh = 42;

public:

	Player(){}
	Player(AnimManager &a, float x, float y, bool dir = 0);

	enum class State : unsigned int { stay, walk, jump, duck, swim, climb } STATE;
	std::map<std::string, bool> key;
	
	void KeyCheck();
	void update(float time, float TileSize, std::vector <std::string> TileMap);
	void Collision(int dir, float TileSize, std::vector <std::string> TileMap);
	void getNumFrame(float num);

	int getNumFrame();
	
	

	bool getDir();

};


//class Enemies : public Player
//{
//public:
//
//	Enemies(AnimManager &a, float x = 100, float y = 100, bool dir = 0);
//	void update(float time, float TileSize, std::vector <std::string> TileMap);
//};