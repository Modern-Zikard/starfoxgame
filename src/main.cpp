#include "ClassAnimationManager.h"

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
    anim.create("run", q, 0, 0, 42, 44, 6, 0.005, 42);
    anim.create("stay", q, 0, 44, 42, 48, 4, 0.005, 42);
    

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
        { 
            anim.flip(true);
            anim.set("run"); 
            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            anim.flip(false);
            anim.set("run");
        }
        
       /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
        {
            if (p.getOnGr()) { p.setDY(-0.4); p.setOnGr(false); }

        }*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            // quit...
            return EXIT_SUCCESS;
            
        }

        anim.tick(time);

        window.clear(sf::Color::White);
        anim.draw(window, 50, 100);
       

       
        window.display();
    }

    return EXIT_SUCCESS;
}