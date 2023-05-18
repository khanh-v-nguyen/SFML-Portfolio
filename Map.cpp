//
// Created by Khanh Nguyen on 12/13/22.
//

#include "Map.h"
sf::Texture Map::safeTexture;
sf::Texture Map::winTexture;

Map::Map()
{
    water.setSize({1920,1080 / 2});
    water.setFillColor(sf::Color::Blue);

    winBar.setSize({1920,100});
    winTexture.loadFromFile("images/finishLine.png");
    winBar.setTexture(&winTexture);

    safeArea.setSize({1920,100});
    safeArea.setPosition({0, 1080/2});
    safeTexture.loadFromFile("grass pic.png");
    safeArea.setTexture(&safeTexture);

    startArea.setTexture(&safeTexture);
    startArea.setPosition({0,1080 - 100});
    startArea.setSize({1920,100});

}

void Map::eventHearts(Player &player1)
{

}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(water);
    target.draw(safeArea);
    target.draw(startArea);
    target.draw(winBar);
}
