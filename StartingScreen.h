//
// Created by Khanh Nguyen on 12/6/22.
//

#ifndef SFML_TEMPLATE_STARTINGSCREEN_H
#define SFML_TEMPLATE_STARTINGSCREEN_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "States.h"
#include "Position.h"

class StartingScreen : public sf::Drawable, public States
{
public:
    StartingScreen();
    StartingScreen(sf::RenderWindow &window);
    sf::RectangleShape startScreen;
    sf::RectangleShape startButton; // on click -> disappear
    sf::Vector2u windowSize;
    sf::Vector2f splashSize;

    static sf::Texture logo;
    static sf::Font font;
    sf::Text play;


    void setUpScreen();
    void eventHandler(sf::RenderWindow &window, const sf::Event &event);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;



};

#endif //SFML_TEMPLATE_STARTINGSCREEN_H
