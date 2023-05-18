//
// Created by Khanh Nguyen on 12/14/22.
//
#include "TophatGuyRun.h"

TophatGuyRun::TophatGuyRun()
{
    sf::RenderWindow window({720,420, 32},"Top Hat Guy");
    window.setFramerateLimit(60);
    TophatGuy t;
    t.setPosition({300,300});

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
            if(sf::Event::Closed == event.type)
                window.close();
        window.clear();
        window.draw(t);
        window.display();
    }

}
