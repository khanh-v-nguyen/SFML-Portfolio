//
// Created by Khanh Nguyen on 12/14/22.
//

#include "TophatGuy.h"
#include <SFML/Graphics.hpp>

TophatGuy::TophatGuy()
{
    top.setSize({50,70});
    brim.setSize({70,25});
    face.setRadius(30);

    sf::FloatRect f = face.getGlobalBounds();
    sf::FloatRect b = brim.getGlobalBounds();
    //sf::FloatRect t = face.getGlobalBounds();

//    top.setPosition({f.left + 5,f.top - 75});
//    brim.setPosition({-f.width / 14, 10});
//    face.setPosition({f.left, f.top});

    top.setPosition({ f.left + b.width/15,f.top - f.height});
    brim.setPosition({-f.width / 14, f.top});
    face.setPosition({f.left, f.top});
}


void TophatGuy::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    states.transform = face.getTransform();
    window.draw(top, states);
    window.draw(brim, states);
    window.draw(face);
}

void TophatGuy::setPosition(sf::Vector2f pos)
{
    sf::Transformable::setPosition(pos);
    face.setPosition(pos);
}

void TophatGuy::setPosition(float x, float y)
{
    setPosition({x,y});
}