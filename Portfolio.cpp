//
// Created by Khanh Nguyen on 12/13/22.
//

#include "Portfolio.h"
sf::Texture Portfolio::backgroundTexture;

Portfolio::Portfolio()
{
    myPortfolio.push_back(PortfolioScreen(COVER));
    myPortfolio.push_back(PortfolioScreen(CROSSYROAD));
    myPortfolio.push_back(PortfolioScreen(CIRCLE));
    myPortfolio.push_back(PortfolioScreen(PONG));
    myPortfolio.push_back(PortfolioScreen(TOPHATGUY));
    myPortfolio.push_back(PortfolioScreen(POKER));


    iter = myPortfolio.begin();

    background.setSize({1920,1080});
    if(!backgroundTexture.loadFromFile("images/blueBackground.jpg"))
    {
        exit(40);
    }
    background.setTexture(&backgroundTexture);


}

void Portfolio::addScreen()
{

}

void Portfolio::eventHandler(sf::RenderWindow &window)
{
    //for iterating through vector of portfolio screens
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || MouseEvents::isClicked(iter->triangleLeft,window))
    {
        if(iter != myPortfolio.begin())
            --iter;
    }
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || MouseEvents::isClicked(iter->triangleRight,window))
    {
        if(iter != myPortfolio.end() - 1)
            ++iter;
    }

    // for checking game type and running game
    if(iter->gameType == CROSSYROAD && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        CrossyRoad();
    }
    if(iter->gameType == CIRCLE && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        GreenCircle();
    }
    if(iter->gameType == PONG && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        PongBallRun();
    }
    if(iter->gameType == TOPHATGUY && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        TophatGuyRun();
    }
    if(iter->gameType == POKER && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        PokerAnalysisRun();
    }

    if(MouseEvents::isHovered(iter->triangleRight, window))
    {
        iter->triangleRight.setFillColor(sf::Color::Green);
    }
    else
    {
        iter->triangleRight.setFillColor(sf::Color::Black);
    }

    if(MouseEvents::isHovered(iter->triangleLeft, window))
    {
        iter->triangleLeft.setFillColor(sf::Color::Green);
    }
    else
    {
        iter->triangleLeft.setFillColor(sf::Color::Black);
    }
}

void Portfolio::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(background);
    target.draw(*iter);
}
