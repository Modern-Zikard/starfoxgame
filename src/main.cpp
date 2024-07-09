
#include "ClassAnimationManager.h"
#include "ClassPers.h"
#include <iostream>


const int H = 12;
const int W = 40;

std::string TileMap[H] = {
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
 "B                                      B",
 "B                                      B",
 "B                                      B",
 "B                                      B",
 "B                         BBBBBBBBBBBBBB",
 "B                                      B",
 "BBBBBBB                                B",
 "B                     BBBBB            B",
 "B                  BBBBBBBBBB          B",
 "B                 BBBBBBBBBBBB         B",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};


int main()
{
 
    sf::RenderWindow window(sf::VideoMode(640, 420), "Game!");

    sf::Texture q;

    AnimManager anim;
    anim.create("walk", q, 0, 0, 42, 44, 6, 0.005, 42);
    anim.create("stay", q, 0, 44, 42, 48, 1, 0.005, 42);
    anim.create("shoot", q, 0, 92, 48, 48, 2, 0.003, 48);
    anim.create("duck", q, 0, 218, 44, 49, 1, 0.003, 44);
    Pers Player(anim);
 
    if (!q.loadFromFile("img//SpriteList.png"))
        return EXIT_FAILURE;
  
    

    sf::Clock clock;

    sf::RectangleShape rectangle;
 
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

        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
            {
                
                if (TileMap[i][j] == 'B') rectangle.setFillColor(sf::Color::Black);
                if (TileMap[i][j] == ' ') continue;
                rectangle.setPosition(j * 32, i * 32);
                window.draw(rectangle);
                //std::cout << "TileMap[" << i << "][" << j << "] = " << TileMap[i][j] << std::endl;
                
            }
       
        Player.update(time);
        Player.draw(window);
        
        window.display();
        
    }

    return EXIT_SUCCESS;
}

//
//
//
//AnimManager anim;
//
//float ax;
//float ay;
//
//float tx;
//float ty;
//
//
//bool toLeft = true;
//
//
//anim.create("run", q, 0, 0, 42, 44, 6, 0.005, 42);
//anim.create("stay", q, 0, 44, 42, 48, 1, 0.005, 42);
//anim.create("shoot", q, 0, 92, 48, 48, 2, 0.003, 48);
//anim.create("duck", q, 0, 218, 44, 49, 1, 0.003, 44);
//
//AnimManager tail;
//
//tail.create("wobble", q, 0, 194, 20, 23, 4, 0.004, 20);
//
//ax = 50;
//ay = 50;
//
//
//anim.set("stay");
//
//
//
//
//tail.set("wobble");
//
//anim.flip(toLeft);
//tail.flip(anim.getAnimFlip());
//
//
//
///* if (!anim.getAnimFlip())tail.draw(window, ax - 1, ay + 6);
// else tail.draw(window, ax + 20, ay + 6);*/
//
//tail.draw(window, tx, ty);
//
//anim.draw(window, ax, ay);
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//{
//    anim.set("run");
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//    {
//        toLeft = true;
//        ax -= 0.08 * time;
//        anim.flip(true);
//
//    }
//
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//    {
//        /*tx = ax - 1;
//        ty = ay + 6;*/
//
//        toLeft = false;
//        ax += 0.08 * time;
//        anim.flip(false);
//    }
//}
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
//{
//    ty = ay + 10;
//    anim.set("duck");
//}
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//{
//    anim.set("shoot");
//}
//
///*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
//{
//    if (p.getOnGr()) { p.setDY(-0.4); p.setOnGr(false); }
//
//}*/
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//{
//    // quit...
//    return EXIT_SUCCESS;
//
//}
//
///*
//
//  */
//if (anim.getAnimFlip())
//{
//    tx = ax + 20;
//    ty = ay + 6;
//}
//else
//{
//    ty = ay + 6;
//    tx = ax - 1;
//}
//tail.tick(time);
//anim.tick(time);