//
// Created by Khanh Nguyen on 12/13/22.
//

#ifndef SFML_TEMPLATE_MAP_H
#define SFML_TEMPLATE_MAP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Position.h"
#include "CarRow.h"
#include "Player.h"
class Map : public sf::Drawable
{
public:
    Map();
    sf::RectangleShape water;
    sf::RectangleShape winBar;
    sf::RectangleShape safeArea;
    sf::RectangleShape startArea;


    static sf::Texture safeTexture;
    static sf::Texture winTexture;


    void eventHearts(Player &player1);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};

#endif //SFML_TEMPLATE_MAP_H
