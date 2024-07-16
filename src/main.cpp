
#include "ClassAnimationManager.h"
#include "ClassPers.h"
#include <iostream>


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
    TileMap.push_back("S                                      S");
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
    TileMap.push_back("S                                      S");
    TileMap.push_back("S                       SSSSSSSSSSSSSSSS");
    TileMap.push_back("S                       SSSSS   SSSSS  S");
    TileMap.push_back("SSSSSSSSSSSSSSSSSSSSSSSSSSSS     SSS   S");
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

    AnimManager anim;
    
    Pers Player(anim, q);
 
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
        }
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) Player.key["Down"] = true;
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))    Player.key["Space"] = true;
     
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
      
       
        Player.update(time, 32, TileMap);
        
        Player.draw(window);

      
        
        window.display();
        
    }

    return EXIT_SUCCESS;
}

