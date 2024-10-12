#include "Map.h"

Map::Map(std::vector<std::string> TileMap, unsigned int TileSize, unsigned int MapHieght, unsigned int MapWidth)
{
	this->TileMap = TileMap;
	this->TileSize = TileSize;
	this->MapHieght = MapHieght;
	this->MapWidth = MapWidth;
}

Map::Map(unsigned int TileSize, unsigned int MapHieght, unsigned int MapWidth)
{
	this->TileSize = TileSize;
	this->MapHieght = MapHieght;
	this->MapWidth = MapWidth;


}

std::vector<std::string> Map::getTileMap(){ return this->TileMap; }

int Map::getTileSize(){ return this->TileSize; }
int Map::getMapHieght(){ return this->MapHieght; }
int Map::getMapWidth(){ return this->MapWidth; }
