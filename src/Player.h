#include "Entity.h"

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
	Player(AnimManager &a, float x, float y, bool dir = 0);
	void KeyCheck();
	void update(float time, float TileSize, std::vector <std::string> TileMap);
	void Collision(int dir, float TileSize, std::vector <std::string> TileMap);
	void getNumFrame(float num);

	int getNumFrame();
	
	float getX();
	float getY();

	bool getDir();

};


