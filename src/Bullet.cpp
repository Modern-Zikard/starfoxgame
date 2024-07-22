//source bullet class

#include "Bullet.h"

Bullet::Bullet(AnimManager a, float x, float y, bool dir)
{
	anim = a;
	anim.set("move");
	this->x = x;
	this->y = y;
	dx = 0.2;
	if (dir == 1) dx = -0.2;
	w = h = 18;
	life = true;


}
void Bullet::update(float time, std::vector <std::string> TileMap)
{
	
	x += dx * time;
	
	for(int i = y/32; i < (y + h)/32; i++)
		for(int j = x/32; j < (x + w)/32; j++)
			if(TileMap[i][j] == 'S')
			{
				
				anim.set("explode");
				dx = 0;
				life = false;
			}
	
	anim.tick(time);
	

}
void Bullet::draw(sf::RenderWindow& window)
{
	anim.draw(window, x, y);
}

bool Bullet::getLife()
{
	return this->life;

}