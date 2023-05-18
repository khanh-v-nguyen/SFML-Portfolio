//
// Created by Khanh Nguyen on 11/14/22.
//

#ifndef SFML_TEMPLATE_DISPLAYCARD_H
#define SFML_TEMPLATE_DISPLAYCARD_H
#include <SFML/Graphics.hpp>
#include "rankEnum.h"
#include "suitEnum.h"


class DisplayCard : public sf::Drawable
{
public:
    DisplayCard(rankEnum rank, suitEnum suit, sf::Vector2f position);
    DisplayCard(rankEnum rank, suitEnum suit);

    sf::RectangleShape background;
    sf::RectangleShape card;
    sf::Text rankText;
    sf::Sprite suitPic;
    sf::Sprite suitPic2;
    static sf::Font font;
    sf::Texture texture;
    rankEnum rank;
    suitEnum suit;

    void setUpCard();
    void setUpSuit();
    void setUpRank();
    void init();
    std::string rankEnumString();
    std::string suitEnumString();

    void draw(sf::RenderTarget& Window, sf::RenderStates states) const;

    void positionNext(std::vector<DisplayCard> cardVector);

    float xPosition, yPosition, spacing;


};
#endif //SFML_TEMPLATE_DISPLAYCARD_H
