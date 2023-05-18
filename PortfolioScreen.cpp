//
// Created by Khanh Nguyen on 12/13/22.
//

#include "PortfolioScreen.h"


sf::Font PortfolioScreen::font;

sf::Texture PortfolioScreen::coverTexture;
sf::Texture PortfolioScreen::crossyTexture;
sf::Texture PortfolioScreen::circleTexture;
sf::Texture PortfolioScreen::pongTexture;
sf::Texture PortfolioScreen::topHatGuyTexture;
sf::Texture PortfolioScreen::pokerTexture;


sf::Texture PortfolioScreen::triangleTexture;
sf::Texture PortfolioScreen::triangleLeftTexture;


PortfolioScreen::PortfolioScreen() : gameType(COVER)
{
    init();
}

PortfolioScreen::PortfolioScreen(GameEnum gameType) : gameType(COVER)
{
    this -> gameType = gameType;
    init();
}

void PortfolioScreen::init()
{
    setUpTexture();
    setUpPic();
    setUpTitle();
    setUpArrows();
}

void PortfolioScreen::setUpTitle()
{
    if(!font.loadFromFile("CHERI___.TTF"))
    {
        exit(30);
    }
    title.setFont(font);

    title.setString(typeToString());
    title.setCharacterSize(100);
    sf::FloatRect t = title.getGlobalBounds();
    title.setPosition({1920/2 - t.width / 2, t.height});
    title.setFillColor(sf::Color::Black);
}

std::string PortfolioScreen::typeToString()
{
    switch(gameType)
    {
        case 1: return "Khanh's Portfolio :D";
        case 2: return "Crossy Road";
        case 3: return "Green Circle";
        case 4: return "Pong and Bouncing Ball";
        case 5: return "Top Hat Guy";
        case 6: return "Poker Analysis + Card";
        default: return "Insert String Here";
    }
}

void PortfolioScreen::setUpPic()
{
    gamePic.setSize({600,600});
    sf::FloatRect g = gamePic.getGlobalBounds();
    gamePic.setPosition({1920 / 2- g.width /2,1080 /2 - g.height /2});
    gamePic.setOutlineColor(sf::Color::Black);
    gamePic.setOutlineThickness(5);

}

void PortfolioScreen::setUpTexture()
{
    switch(gameType)
    {
        case 1:
        {
            if(!coverTexture.loadFromFile("images/c++ cat.jpg"))
            {
                exit(31);
            }
            gamePic.setTexture(&coverTexture);
            break;
        }
        case 2:
        {
            if(!crossyTexture.loadFromFile("images/crossy.png"))
            {
                exit(32);
            }
            gamePic.setTexture(&crossyTexture);
            break;
        }
        case 3:
        {
            if(!circleTexture.loadFromFile("images/green circle.png"))
            {
                exit(33);
            }
            gamePic.setTexture(&circleTexture);
            break;
        }
        case 4:
        {
            if (!pongTexture.loadFromFile("images/pongPic.png")) {
                exit(34);
            }
            gamePic.setTexture(&pongTexture);
            break;
        }
        case 5:
        {
            if (!topHatGuyTexture.loadFromFile("images/topHatPic.png")) {
                exit(34);
            }
            gamePic.setTexture(&topHatGuyTexture);
            break;
        }
        case 6: {
            if (!pokerTexture.loadFromFile("images/pokerAnalysisPic.png")) {
                exit(35);
            }
            gamePic.setTexture(&pokerTexture);
            break;
        }
    }
}

void PortfolioScreen::setUpArrows()
{
    triangleLeft.setSize({100,100});
    triangleRight.setSize({100,100});

    triangleTexture.loadFromFile("images/rightPinkArrow.png");
    triangleLeftTexture.loadFromFile("images/leftPinkArrow.png");

    triangleRight.setTexture(&triangleTexture);
    triangleRight.setFillColor(sf::Color::Black);

    triangleLeft.setTexture(&triangleLeftTexture);
    triangleLeft.setFillColor(sf::Color::Black);

    sf::FloatRect g = gamePic.getGlobalBounds();
    sf::FloatRect tleft = triangleLeft.getGlobalBounds();

    triangleLeft.setPosition({g.left - 2 * tleft.width, g.top + g.height /2});
    triangleRight.setPosition({g.left + g.width + tleft.width, g.top + g.height /2});

}

void PortfolioScreen::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(gameType == CROSSYROAD && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        CrossyRoad();
    }
    if(gameType == CIRCLE && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {

    }
}

void PortfolioScreen::gamePressed()
{

}

void PortfolioScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(gamePic);
    target.draw(title);
    target.draw(triangleLeft);
    target.draw(triangleRight);

}



