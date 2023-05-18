//
// Created by Khanh Nguyen on 12/14/22.
//

#ifndef SFML_TEMPLATE_WINLOSE_H
#define SFML_TEMPLATE_WINLOSE_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "CarRow.h"
#include "Position.h"
#include "MouseEvents.h"
#include "ListItem.h"
#include "StartingScreen.h"

class WinLose : public sf::Drawable
{
public:
    WinLose();
    void setUpHearts();
    void setUpText();
    void eventHandler(Player &player, sf::RenderWindow &window, sf::Event &event);
    void setUpBox();
    std::vector<sf::RectangleShape> hearts;
    static sf::Texture heartsTexture;
    static sf::Font font;

    ListItem newBox;
    StartingScreen splash;

    sf::RectangleShape winLoseBox;
    sf::Text playAgain;
    sf::Text exit;
    sf::Text winOrLose;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif //SFML_TEMPLATE_WINLOSE_H
