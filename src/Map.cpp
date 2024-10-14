#include "Map.h"


Map::Map()
{
    this->TileSize = 32;
    this->MapHieght = 8;
    this->MapWidth = 8;
}

Map::Map(std::vector<std::string> TileMap, std::vector<sf::Sprite> Tiles, unsigned int TileSize)
{
    this->Tiles = Tiles;
    this->TileMap = TileMap;
    this->MapHieght = TileMap.size();
    if (TileMap.size() > 0) this->MapWidth = TileMap[0].size();
}




void Map::MapDraw(sf::RenderWindow &window)
{
    
   /* for (int i = 0; i < MapHieght; i++)
    {
        for (int j = 0; j < MapWidth; j++)
        {
            if (TileMap[i][j] == '0') Grow.setTextureRect(sf::IntRect(32, 0, 32, 32));
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
