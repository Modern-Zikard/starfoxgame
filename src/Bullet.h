//header class bullet

#include "ClassAnimationManager.h"


class Bullet
{
private:

	AnimManager anim;

	float dx = 0;
	float dy = 0;
	float x;
	float y;
	float w;
	float h;

	bool life;

public:
	Bullet(AnimManager a, float x, float y, bool dir);
	void update(float time, std::vector <std::string> TileMap);
	void draw(sf::RenderWindow& window);

	bool getLife();
};