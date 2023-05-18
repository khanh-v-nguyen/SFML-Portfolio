//
// Created by Khanh Nguyen on 11/14/22.
//


#include "DisplayCard.h"
sf::Font DisplayCard::font;

DisplayCard::DisplayCard(rankEnum rank, suitEnum suit, sf::Vector2f position)
{
    this -> rank = rank;
    this -> suit = suit;
    card.setPosition(position);
    init();

    sf::FloatRect c = card.getGlobalBounds();
    this -> xPosition = c.left;
    this -> yPosition = c.top;
    this -> spacing = c.width + c.width /4;
}

DisplayCard::DisplayCard(rankEnum rank, suitEnum suit)
{
    this -> rank = rank;
    this -> suit = suit;
    init();
}


void DisplayCard::init()
{
    setUpCard();
    setUpSuit();
    setUpRank();

}



void DisplayCard::draw(sf::RenderTarget& Window, sf::RenderStates states) const
{
    Window.draw(card);
    Window.draw(rankText);
    Window.draw(suitPic);
    Window.draw(suitPic2);
}


void DisplayCard::setUpCard()
{
    card.setSize({125,150});
}

void DisplayCard::setUpRank()
{
    sf::FloatRect c = card.getGlobalBounds();
    if(!font.loadFromFile("/Users/khanh/CLionProjects/PokerAnalysis/fonts/OpenSans-Bold.ttf"))
        exit(20);

    rankText.setFont(font);
    rankText.setPosition({c.left + c.width/2, c.top + c.height/2});
    rankText.setString(rankEnumString());
}

void DisplayCard::setUpSuit()
{
    sf::FloatRect c = card.getGlobalBounds();
    if(!texture.loadFromFile(suitEnumString()))
    {
        exit(21);
    }

    suitPic.setTexture(texture);
    suitPic2.setTexture(texture);

    suitPic.setScale({0.5,0.5});
    suitPic.setPosition({c.left, c.top});
    suitPic2.setScale({0.5,0.5});
    suitPic2.setPosition({c.left + c.width, c.top + c.height});
    suitPic2.rotate(180);


    if(suit == CLUBS || suit == SPADES)
    {
        rankText.setColor(sf::Color::Black);
    }
    else
    {
        rankText.setColor(sf::Color::Red);
    }
}


std::string DisplayCard::rankEnumString()
{
    switch(rank) {
        case 1:
            return "A";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
    }
}

std::string DisplayCard::suitEnumString()
{
    switch(suit)
    {
        case CLUBS:
            return "PokerAnalysisFiles/club.png";
        case DIAMONDS:
            return "PokerAnalysisFiles/diamonds.png";
        case HEARTS:
            return "PokerAnalysisFiles/heart.png";
        case SPADES:
            return "PokerAnalysisFiles/spades.png";
    }
}

