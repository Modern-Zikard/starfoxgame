#pragma once

#include "ClassAnimationManager.h"

class Map
{
private:
	std::vector <std::string> TileMap;
	std::map<char, bool> key;

	unsigned int TileSize;
	unsigned int MapHieght;
	unsigned int MapWidth;

	sf::Sprite Grow;
	sf::Sprite Stone;
	sf::Sprite Sky;

public:
	Map(){};
	Map(std::vector <std::string> TileMap, unsigned int TileSize);
	

	void MapSetParameters(unsigned int TileSize, unsigned int MapHieght, unsigned int MapWidth);
	void MapDraw(sf::RenderWindow &window);
	std::vector <std::string> getTileMap();

	int getTileSize();
	int getMapHieght();
	int getMapWidth();
};