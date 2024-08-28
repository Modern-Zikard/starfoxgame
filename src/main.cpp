
#include "ClassAnimationManager.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "Bullet.h"
#include <iostream>
#include <list>


int WindH = 720;
int WindW = 1280;

const int H = 20;
const int W = 40;

std::string TileMap[H] = {
 "B                                      S",
 "B                                      S",
 "B                                      S",
 "B                                      S",
 "B                                      S",
 "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
 "B                              SSSSSSS B",
 "BBBBBBB                         SSSSS  B",
 "B                                SSS   S",
 "B                                SSS   S",
 "B                                 S    S",
 "B                                 S    S",
 "B                       SSSSSSSSSSSSSSSS",
 "B                       SSSSSSSSSSSSSSSS",
 "B                       SSSSS   SSSSS  B",
 "BBBBBBB                  SSS     SSS   B",
 "B                     KKKKSS     SSS   B",
 "B                  GGGGGGGGG      S    B",
 "B                 GBBBBBBBBBGG    S    B",
 "BGGGGGGGGGGGGGGGGGBBBBBBBBBBBBGGGGGGGGGB"
};




int main()
{
    std::vector <std::string> TileMap;
    TileMap.push_back("SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS");
    TileMap.push_back("S                                      S");
    TileMap.push_back("S                                      S");
    TileMap.push_back("S                                      S");
    TileMap.push_back("S                                      S");
    TileMap.push_back("S                                      S");
    TileMap.push_back("S                              SSSSSSS S");
    TileMap.push_back("S                                      S");
    TileMap.push_back("S                                      S");
    TileMap.push_back("S                                      S");
    TileMap.push_back("S                                      S");
    TileMap.push_back("S                               KKKKKKKS");
    TileMap.push_back("S                       SSSSSSSSSSSSSSSS");
    TileMap.push_back("S                       SSSSS   SSSSS  S");
    TileMap.push_back("SSSSSSSSS    SSSSSSSSSSSSSSS     SSS   S");
    TileMap.push_back("S                     SSSSSS     SSS   S");
    TileMap.push_back("S                  SSSSSSSSS      S    S");
    TileMap.push_back("S                 SSSSSSSSSSSS    S    S");
    TileMap.push_back("SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS");
    TileMap.push_back("SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS");



    
    
    sf::RenderWindow window(sf::VideoMode(WindW, WindH), "Game!");

    sf::View Player_view;
    Player_view.reset(sf::FloatRect(0, 0, WindW/2, WindH/2));

    sf::Texture q;

    sf::Texture t_tile;
    sf::Sprite s_tile;
    s_tile.setTexture(t_tile);


    AnimManager Fox;
    

    Fox.create("walk", q, 0, 0, 42, 44, 6, 0.005, 42);
    Fox.create("stay", q, 0, 44, 42, 48, 1, 0.005, 42);
    Fox.create("shoot", q, 0, 92, 60, 48, 5, 0.006, 60);
    Fox.create("duck", q, 0, 218, 44, 49, 1, 0.003, 44);
    Fox.create("shootrun", q, 0, 267, 59, 44, 6, 0.006, 59);
    Fox.create("jump", q, 0, 140, 40, 54, 1, 0.005, 40);

    AnimManager Shoot;

    Shoot.create("move", q, 0, 318, 6, 6, 3, 0.005, 6);
    Shoot.create("explode", q, 0, 325, 7, 10, 3, 0.0001, 7);
    
    Player Krystal(Fox, 100, 100);
    

    std::list<Entity*> entities;
    std::list<Entity*>::iterator it;

    entities.push_back(new Enemy(Fox, 780, 339));
    entities.push_back(new Enemy(Fox, 50, 300));
    entities.push_back(new Enemy(Fox, 1200, 300));
 
    if (!q.loadFromFile("img//SpriteList.png"))
        return EXIT_FAILURE;
    if (!t_tile.loadFromFile("img//Tiles.png"))
        return EXIT_FAILURE;
    
   
    
    

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
                if((event.key.code == sf::Keyboard::Space)/*&&(Krystal.getNumFrame() == 1)*/)
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

        for (int i = 0; i < H; i++)
        {
            
            for (int j = 0; j < W; j++)
            {
                if (TileMap[i][j] == 'K') s_tile.setTextureRect(sf::IntRect(32, 0, 32, 32));
                if (TileMap[i][j] == 'S') s_tile.setTextureRect(sf::IntRect(0, 0, 32, 32));
                if (TileMap[i][j] == ' ') s_tile.setTextureRect(sf::IntRect(64, 0, 32, 32));

                s_tile.setPosition(j * 32, i * 32);
                window.draw(s_tile);
                
            }
        }

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
            (*it)->update(time,32, TileMap);
            (*it)->draw(window);

        }
            
       

        Krystal.update(time,32, TileMap);
        
        
        /*std::cout << "Frame Num = " << Krystal.getNumFrame() << std::endl;*/
        Krystal.draw(window);
        
        
        Player_view.setCenter(Krystal.getX(), Krystal.getY());

        window.setView(Player_view);
      
        
        window.display();
        
    }

    return EXIT_SUCCESS;
}

