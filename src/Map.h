#pragma once

#include "ClassAnimationManager.h"

class Map
{
private:
	std::vector <std::string> TileMap;
	std::vector <sf::Sprite> Tiles;

	unsigned int TileSize;
	unsigned int MapHieght;
	unsigned int MapWidth;

public:
	Map();
	Map(std::vector <std::string> TileMap, std::vector <sf::Sprite> Tiles, unsigned int TileSize);
	
	
	
	void MapSetParameters(unsigned int TileSize, unsigned int MapHieght, unsigned int MapWidth);
	void MapDraw(sf::RenderWindow &window);


	std::vector <std::string> getTileMap();

	int getTileSize();
	int getMapHieght();
	int getMapWidth();
};