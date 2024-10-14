#include "Map.h"

Map::Map(std::vector<std::string> TileMap, unsigned int TileSize)
{
	this->TileMap = TileMap;
	this->TileSize = TileSize;
	this->MapHieght = TileMap.size();
	if(TileMap.size() > 0) this->MapWidth = TileMap[0].size();
}

//Map::Map(unsigned int TileSize, unsigned int MapHieght, unsigned int MapWidth)
//{
//	this->TileSize = TileSize;
//	this->MapHieght = MapHieght;
//	this->MapWidth = MapWidth;
//
//
//}

void Map::MapDraw(sf::RenderWindow& window)
{
    ///////////Доработать! 
   /* for (int i = 0; i < MapHieght; i++)
    {
        for (int j = 0; j < MapWidth; j++)
        {
            if (TileMap[i][j] == 'G') Grow.setTextureRect(sf::IntRect(32, 0, 32, 32));
            if (TileMap[i][j] == 'S') Stone.setTextureRect(sf::IntRect(0, 0, 32, 32));
            if (TileMap[i][j] == ' ') Sky.setTextureRect(sf::IntRect(64, 0, 32, 32));
            s_tile.setPosition(j * 32, i * 32);
            window.draw(s_tile);
        }
    }*/
}

std::vector<std::string> Map::getTileMap(){ return this->TileMap; }

int Map::getTileSize(){ return this->TileSize; }
int Map::getMapHieght(){ return this->MapHieght; }
int Map::getMapWidth(){ return this->MapWidth; }
