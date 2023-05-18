//
// Created by Khanh Nguyen on 11/9/22.
//

#ifndef SFML_TEMPLATE_DRAWCARD_H
#define SFML_TEMPLATE_DRAWCARD_H
#include <SFML/Graphics.hpp>
#include "rankEnum.h"
#include "suitEnum.h"
#include "PokerScore.h"
#include "Position.h"

class DrawCard : public sf::Drawable
{
public:
    DrawCard();
    DrawCard(rankEnum rank, suitEnum suit);
    void draw(sf::RenderTarget& Window, sf::RenderStates states) const;
    void setCardPosition(sf::Vector2f vector2f);

    int cardWidth;
    int cardHeight;
    void setAllPositions();

    sf::FloatRect getGlobalBounds();

private:
    sf::RectangleShape background;
    sf::RectangleShape card;

    rankEnum cardRank;
    suitEnum cardSuit;
    sf::Text rank;
    sf::Text scoreName;
    sf::Sprite suitPic;
    sf::Sprite suitPic2;

    static sf::Texture texture;

//    static sf::Texture clubTexture;
//    static sf::Texture diamondTexture;
//    static sf::Texture heartsTexture;
//    static sf::Texture spadesTexture;


    static sf::Font font;

    std::string rankEnumString();
    std::string suitEnumString();

    void setBackground();
    void setUpCard();
    void setUpSuit();
    void setUpRank();
    void setUpStats();

    sf::Text ryText;
    sf::Text ryStats;


};

#endif //SFML_TEMPLATE_DRAWCARD_H
