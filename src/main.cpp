
#include "ClassAnimationManager.h"
#include "ClassPers.h"
#include "Bullet.h"
#include <iostream>
#include <list>


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



    
    
    sf::RenderWindow window(sf::VideoMode(1280, 640), "Game!");

    sf::Texture q;

    

    sf::Texture Green;
    sf::Texture Brow;
    sf::Texture Kust;
    sf::Texture Sky;
    sf::Texture Stone;

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
    
    Pers Player(Fox, q);
    

    std::list<Bullet*> bullets;
    std::list<Bullet*>::iterator it; 
 
    if (!q.loadFromFile("img//SpriteList.png"))
        return EXIT_FAILURE;
    if (!Green.loadFromFile("img//GreenTile1.png"))
        return EXIT_FAILURE;
    if (!Sky.loadFromFile("img//BlueSkyTile.png"))
        return EXIT_FAILURE;
    if (!Brow.loadFromFile("img//BrowTile.png"))
        return EXIT_FAILURE;
    if (!Kust.loadFromFile("img//KustTile.png"))
        return EXIT_FAILURE;
    if (!Stone.loadFromFile("img//StoneTile.png"))
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
                if(event.key.code == sf::Keyboard::Space)
                    bullets.push_back(new Bullet(Shoot, Player.getX()+54, Player.getY()+10, Player.getDir()));
        }
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) Player.key["Down"] = true;
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            Player.key["Space"] = true;
            
         
     
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))     Player.key["Left"] = true;
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))    Player.key["Right"] = true;
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))       Player.key["Up"] = true;
       

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
                if (TileMap[i][j] == 'K') rectangle.setTexture(&Kust);
                if (TileMap[i][j] == 'S') rectangle.setTexture(&Stone);
                if (TileMap[i][j] == 'B') rectangle.setTexture(&Brow);
                if (TileMap[i][j] == 'G') rectangle.setTexture(&Green);
                if (TileMap[i][j] == ' ') rectangle.setTexture(&Sky);
                rectangle.setPosition(j * 32, i * 32);
                window.draw(rectangle);
                
            }
        }

        for (it = bullets.begin(); it != bullets.end();)
        {
            Bullet* b = *it;
            if (b->getLife() == false)
            {
                it = bullets.erase(it);
                delete b;
            }
            else it++;
        }
        
        for (it = bullets.begin(); it != bullets.end(); it++)
        {
            (*it)->update(time, TileMap);
            (*it)->draw(window);

        }
            
       

        Player.update(time, 32, TileMap);
       
        Player.draw(window);
        
        

      
        
        window.display();
        
    }

    return EXIT_SUCCESS;
}

