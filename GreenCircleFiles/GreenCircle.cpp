//
// Created by Khanh Nguyen on 12/13/22.
//

#include "GreenCircle.h"

GreenCircle::GreenCircle()
{
    sf::RenderWindow window(sf::VideoMode(500, 500, 32), "Green Circle");
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Green);
    circle.setRadius(250.f);

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(circle);

        window.display();
    }
}

