#pragma once

#include "ClassAnimationManager.h"

class Map
{
private:
	std::vector <std::string> TileMap;

	unsigned int TileSize;
	unsigned int MapHieght;
	unsigned int MapWidth;

public:
	Map(){};
	Map(std::vector <std::string> TileMap, unsigned int TileSize, unsigned int MapHieght, unsigned int MapWidth);
	Map(unsigned int TileSize, unsigned int MapHieght, unsigned int MapWidth);

	std::vector <std::string> getTileMap();

	int getTileSize();
	int getMapHieght();
	int getMapWidth();
};