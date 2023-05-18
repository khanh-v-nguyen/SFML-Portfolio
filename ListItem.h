//
// Created by Khanh Nguyen on 12/7/22.
//

#ifndef SFML_TEMPLATE_LISTITEM_H
#define SFML_TEMPLATE_LISTITEM_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "States.h"

class ListItem : public sf::Drawable, public States
{
public:
    ListItem();
    ListItem(std::string texture);
    ListItem(std::string buttonName, sf::Vector2f boxSize);
    ListItem(std::string buttonName, sf::Vector2f boxSize, sf::Vector2f position);

    sf::RectangleShape box;
    sf::Text buttonText;
    static sf::Font font;
    static sf::Texture listTexture;

    sf::Vector2f boxSize;
    sf::Vector2f position;
    std::string buttonName;

    void setPosition(sf::Vector2f pos);

    void setUpBox();
    void setUpText();

    sf::FloatRect getGlobalBounds();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_LISTITEM_H
