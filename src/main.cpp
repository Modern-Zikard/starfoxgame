#include "ClassAnimationManager.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Map.h"
#include <iostream>
#include <list>

int WindH = 720;
int WindW = 1280;

int main()
{
    std::vector <std::string> TileMap;
    TileMap.push_back("111111111111111111111111111111111111111111111111111");
    TileMap.push_back("100000000000000000000000000000000000000000000000001");
    TileMap.push_back("100000000000000000000000000000000000000000000000001");
    TileMap.push_back("100000000000000000000000000000000000000000000000001");
    TileMap.push_back("100000000000000000000000000000000000000000000000001");
    TileMap.push_back("100000000000000000000000000000000000000000000000001");
    TileMap.push_back("100000000000000000000000000000000000000011111111111");
    TileMap.push_back("100000000000000000000000000000000000000000000000001");
    TileMap.push_back("100000000000000000000000000000000000000000000000001");
    TileMap.push_back("100000000000000000022200000000222222222222000000001");
    TileMap.push_back("100000000000000000211122220000000000000000000000001");
    TileMap.push_back("100000000000000002100111112200000000000000000222221");
    TileMap.push_back("100000000000000021000000111122000000000000002111111");
    TileMap.push_back("111110000000000000000011111111100000000000021111111");
    TileMap.push_back("111111111000000000000111111000000000000000211111111");
    TileMap.push_back("100000000100000000000011110000000000000002100000001");
    TileMap.push_back("100000000000011111111111000000000000000210000000001");
    TileMap.push_back("100000000000000000000000100000000000000210000000001");
    TileMap.push_back("122222222222222222222222222222222222222222222222221");
    TileMap.push_back("111111111111111111111111111111111111111111111111111");



    std::vector <sf::Sprite> s_tiles;
   

    std::vector <std::string> TestTileMap;
    TestTileMap.push_back("11111111");
    TestTileMap.push_back("10000001");
    TestTileMap.push_back("10000001");
    TestTileMap.push_back("10000001");
    TestTileMap.push_back("10000111");
    TestTileMap.push_back("10000001");
    TestTileMap.push_back("10000221");
    TestTileMap.push_back("11111111");

 

    sf::RenderWindow window(sf::VideoMode(WindW, WindH), "Game!");
    sf::View Player_view;

    Player_view.reset(sf::FloatRect(0, 0, WindW/2, WindH/2));

    sf::Texture FoxTexture;
    sf::Texture TileTexture;
    
    AnimManager Fox;
    AnimManager Shoot;

  /*  s_tile.setTexture(t_tile);*/
    
    Fox.create("walk", FoxTexture, 0, 0, 60, 54, 6, 0.005, 60);
    Fox.create("stay", FoxTexture, 0, 486, 60, 54, 1, 0.005, 60);
    Fox.create("shoot", FoxTexture, 0, 108, 60, 54, 5, 0.006, 60);
    Fox.create("duck", FoxTexture, 0, 218, 44, 49, 1, 0.003, 44);
    Fox.create("shootrun", FoxTexture, 0, 216, 60, 54, 5, 0.006, 60);
    Fox.create("jump", FoxTexture, 0, 432, 60, 54, 1, 0.005, 60);

    Shoot.create("move", FoxTexture, 0, 318, 6, 6, 3, 0.005, 6);
    Shoot.create("explode", FoxTexture, 0, 325, 7, 10, 3, 0.0001, 7);
    
    Player Krystal(Fox, 50, 50);
    
    std::list<Entity*> entities;
    std::list<Entity*>::iterator it;

   /* entities.push_back(new Enemy(Fox, 780, 339));*/
    /*entities.push_back(new Enemy(Fox, 100, 50));*/
    entities.push_back(new Enemy(Fox, 100, 50));
    /*entities.push_back(new Enemy(Fox, 1200, 300));*/
 
    if (!FoxTexture.loadFromFile("img//FoxSpriteList.png"))
        return EXIT_FAILURE;
   /* if (!t_tile.loadFromFile("img//Tiles.png"))
        return EXIT_FAILURE;*/
    if (!TileTexture.loadFromFile("img//TileSet.png"))
        return EXIT_FAILURE;
   
    Map Test(TileMap, TileTexture, 32);
    
    sf::Clock clock;
    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(32, 32));
 
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;
        sf::Event event;
       
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                if((event.key.code == sf::Keyboard::Space))
                    entities.push_back(new Bullet(Shoot, Krystal.getDir() ? Krystal.getX() : Krystal.getX()+54, Krystal.getY()+11, Krystal.getDir()));
        }
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) Krystal.key["Down"] = true;
  
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            Krystal.key["Space"] = true;
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))     Krystal.key["Left"] = true;
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))    Krystal.key["Right"] = true;
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))       Krystal.key["Up"] = true;
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            // quit...
            return EXIT_SUCCESS;
        }
        
        window.clear(sf::Color::White);

       
        Test.MapDraw(window);
        

        for (it = entities.begin(); it != entities.end();)
        {
            Entity* b = *it;
            if (b->getLife() == false)
            {
                it = entities.erase(it);
                delete b;
            }
            else it++;
        }
        
        for (it = entities.begin(); it != entities.end(); it++)
        {
            (*it)->update(time,Test.getTileSize(), Test.getTileMap());
            (*it)->draw(window);
        }

        Krystal.update(time, Test.getTileSize(), Test.getTileMap());
        Krystal.draw(window);
        
        Player_view.setCenter(Krystal.getX(), Krystal.getY());

        window.setView(Player_view);
        window.display();
    }
    return EXIT_SUCCESS;
}