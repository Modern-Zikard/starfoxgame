#include "ClassAnimationManager.h"
#include <iostream>



int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(640, 420), "Game!");

    // Create a graphical text to display
   

        // Load a sprite to display
    sf::Texture q;
 
    if (!q.loadFromFile("img//SpriteList.png"))
        return EXIT_FAILURE;
  
    
    AnimManager anim;

    float ax;
    float ay;

    float tx;
    float ty;


    bool toLeft = true;
   
 
    anim.create("run", q, 0, 0, 42, 44, 6, 0.005, 42);
    anim.create("stay", q, 0, 44, 42, 48, 1, 0.005, 42);
    anim.create("shoot", q, 0, 92, 48, 48, 2, 0.003, 48);
    anim.create("duck", q, 0, 218, 44, 49, 1, 0.003, 44);

    AnimManager tail;

    tail.create("wobble", q, 0, 194, 20, 23, 4, 0.004, 20);
    
    ax = 50;
    ay = 50;

    sf::Clock clock;
 
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time /= 800;
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        anim.set("stay");
       

        

        tail.set("wobble");

        
            
        

        

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        { 
            
            anim.set("run"); 

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                
                
                toLeft = true;
                ax -= 0.05 * time;
                anim.flip(true);
                

            }
                
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                /*tx = ax - 1;
                ty = ay + 6;*/
                
                toLeft = false;
                ax += 0.05 * time;
                anim.flip(false);
                
                

            }


            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
        {
            
            ty = ay + 10;

            anim.set("duck");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            
            
            anim.set("shoot");
        }
        
        
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
        {
            if (p.getOnGr()) { p.setDY(-0.4); p.setOnGr(false); }

        }*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            // quit...
            return EXIT_SUCCESS;
            
        }

      /*  
        
        */
        if (anim.getAnimFlip())
        {
            tx = ax + 20;
            ty = ay + 6;
        }
        else
        {
            ty = ay + 6;
            tx = ax - 1;
        }
        tail.tick(time);
        anim.tick(time);
        

        window.clear(sf::Color::White);
        anim.flip(toLeft);
        tail.flip(anim.getAnimFlip());

        
        
       /* if (!anim.getAnimFlip())tail.draw(window, ax - 1, ay + 6);
        else tail.draw(window, ax + 20, ay + 6);*/

        tail.draw(window, tx, ty);
        
        anim.draw(window, ax, ay);
        
        
        
        window.display();
    }

    return EXIT_SUCCESS;
}