#include "Map.h"




Map::Map(std::vector<std::string> &TileMap, sf::Texture &TileTexture, unsigned int TileSize)
{
  
    TileSprite.setTexture(TileTexture);
    this->TileSize = TileSize;
    this->TileMap = TileMap;
    this->MapHieght = TileMap.size();
    if (TileMap.size() > 0) this->MapWidth = TileMap[0].size();
}

void Map::MapDraw(sf::RenderWindow &window)
{
    for (int i = 0; i < MapHieght; i++)
    {
        for (int j = 0; j < MapWidth; j++)
        {
            if (TileMap[i][j] == '0') TileSprite.setTextureRect(sf::IntRect(0, 0, TileSize, TileSize));
            if (TileMap[i][j] == '1') TileSprite.setTextureRect(sf::IntRect(32, 0, TileSize, TileSize));
            if (TileMap[i][j] == '2') TileSprite.setTextureRect(sf::IntRect(64, 0, TileSize, TileSize));
            TileSprite.setPosition(j * TileSize, i * TileSize);
            window.draw(TileSprite);
        }
    }
}

std::vector<std::string> Map::getTileMap(){ return this->TileMap; }
sf::Sprite Map::getSprite(){ return TileSprite; }

int Map::getTileSize(){ return this->TileSize; }
int Map::getMapHieght(){ return this->MapHieght; }
int Map::getMapWidth(){ return this->MapWidth; }
