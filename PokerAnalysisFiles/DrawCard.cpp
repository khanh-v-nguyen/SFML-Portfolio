//
// Created by Khanh Nguyen on 11/9/22.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DrawCard.h"

sf::Font DrawCard::font;
sf::Texture DrawCard::texture;

DrawCard::DrawCard()
{

};

DrawCard::DrawCard(rankEnum rank, suitEnum suit)
{
    this -> cardRank = rank;
    this -> cardSuit = suit;

    setBackground();
    setUpCard();
    setUpRank();
    setUpSuit();
    setUpStats();

    sf::FloatRect c = card.getGlobalBounds();
    this -> cardHeight = c.height;
    this -> cardWidth = c.width;
}

void DrawCard::draw(sf::RenderTarget& Window, sf::RenderStates states) const
{
    Window.draw(background);
    Window.draw(card);
    Window.draw(rank);
    Window.draw(suitPic);
    Window.draw(suitPic2);
    Window.draw(ryText);
    Window.draw(ryStats);

}

void DrawCard::setCardPosition(sf::Vector2f vector2f)
{

    card.setPosition(vector2f);
    setUpRank();
    setUpSuit();

//    rank.move(vector2f);
//    suitPic.move(vector2f);
//    suitPic2.move(vector2f);

}

void DrawCard::setUpCard()
{
    card.setSize({100,150});
    card.setFillColor(sf::Color::White);
    //card.setPosition({200,200});
    card.setOutlineThickness(5);
    card.setOutlineColor(sf::Color::Black);
}

void DrawCard::setBackground()
{
    background.setFillColor(sf::Color::Blue);
    background.setSize({1920, 1080});
}

void DrawCard::setUpRank() {
    sf::FloatRect c = card.getGlobalBounds();

    if (!font.loadFromFile("/Users/khanh/CLionProjects/PokerAnalysis/fonts/OpenSans-Bold.ttf"))
        exit(20);
    rank.setFont(font);
    rank.setCharacterSize(50);
    rank.setString(rankEnumString());

    sf::FloatRect r = rank.getGlobalBounds();
    rank.setOrigin({r.width / 2, r.height / 2});
    rank.setPosition(c.left + c.width / 2, c.top + c.height / 2);
}

void DrawCard::setUpSuit()
{
    sf::FloatRect c = card.getGlobalBounds();
    sf::FloatRect r = rank.getGlobalBounds();


    if(!texture.loadFromFile(suitEnumString()))
    {
        exit(21);
    }

    suitPic.setTexture(texture);
    suitPic.setScale({static_cast<float>(c.width * 0.005),static_cast<float>(c.width * 0.005)});
    suitPic.setPosition({c.left, c.top});

    suitPic2.setTexture(texture);
    suitPic2.rotate(90);
    suitPic2.setScale({static_cast<float>(c.width * 0.005),static_cast<float>(c.width * 0.005)});
    suitPic2.setPosition({c.left + c.width - (c.width / 10), c.top + c.height - (c.height / 10)});


    sf::FloatRect s = suitPic.getGlobalBounds();
    //suitPic.setOrigin({s.width/2, s.height/2});

    if(cardSuit == CLUBS || cardSuit == SPADES)
    {
        rank.setColor(sf::Color::Black);
        suitPic.setColor(sf::Color::Black);
        suitPic2.setColor(sf::Color::Black);
    }
    else
    {
        rank.setColor(sf::Color::Red);
        suitPic.setColor(sf::Color::Red);
        suitPic2.setColor(sf::Color::Red);
    }

}

std::string DrawCard::rankEnumString()
{
    switch(cardRank) {
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

std::string DrawCard::suitEnumString()
{
    switch(cardSuit)
    {
        case CLUBS:
            return "club.png";
        case DIAMONDS:
            return "diamonds.png";
        case HEARTS:
            return "heart.png";
        case SPADES:
            return "spades.png";
    }
}

void DrawCard::setUpStats()
{
    if (!font.loadFromFile("/Users/khanh/CLionProjects/PokerAnalysis/fonts/OpenSans-Bold.ttf"))
        exit(20);
    ryText.setFont(font);
    ryText.setCharacterSize(50);
    ryText.setString("Royal Flush 1: "); // is there a way to add more values to this
    ryText.setPosition({100,100});

    ryStats.setFont(font);
    ryStats.setCharacterSize(50);


    ryStats.setString(std::to_string(PokerScore::HCCOUNTER / PokerScore::RFCOUNTER));
    ryStats.setPosition({450, 100});
}

sf::FloatRect DrawCard::getGlobalBounds()
{
    sf::FloatRect a = card.getGlobalBounds();
    return a;
}
