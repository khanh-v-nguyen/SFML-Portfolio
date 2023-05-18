//
// Created by Khanh Nguyen on 12/6/22.
//

#include "StartingScreen.h"

sf::Texture StartingScreen::logo;
sf::Font StartingScreen::font;


StartingScreen::StartingScreen()
{
    setUpScreen();
}

StartingScreen::StartingScreen(sf::RenderWindow &window)
{
    this -> windowSize = window.getSize();
    setUpScreen();
}

void StartingScreen::setUpScreen()
{
    logo.loadFromFile("images/crossySplash.png");
    font.loadFromFile("PIXELADE.TTF");

    startScreen.setSize({1920,1080});
    //startScreen.setFillColor(sf::Color::Blue);
    startScreen.setTexture(&logo);

    startButton.setSize({300,100});
    startButton.setPosition(1920/2 - startButton.getSize().x / 2,1080/2 + startButton.getSize().y * 2);

    sf::FloatRect s = startButton.getGlobalBounds();
    play.setFont(font);
    play.setString("start");
    play.setCharacterSize(75);
    sf::FloatRect p = play.getGlobalBounds();
    play.setPosition({s.left + s.width/2 - p.width/2, s.top});
}

void StartingScreen::eventHandler(sf::RenderWindow &window, const sf::Event &event)
{
    if(MouseEvents::isHovered(startButton, window))
    {
        startButton.setFillColor(sf::Color::Green);
        play.setFillColor(sf::Color::Black);

    }
    else
    {
        startButton.setFillColor(sf::Color::Blue);
        startButton.setOutlineThickness(2);
        startButton.setOutlineColor(sf::Color::White);
        play.setFillColor(sf::Color::White);
    }

    if(MouseEvents::isClicked(startButton, window))
    {
//        startButton.setFillColor(sf::Color::Transparent);
//        startButton.setPosition({-100,-100});
//
//        startScreen.setFillColor(sf::Color::Transparent);
//        play.setFillColor(sf::Color::Transparent);
        this->enableStates(HIDDEN);
        //startScreen.setSize(splashSize);
    }
}

void StartingScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(!this->checkStates(HIDDEN))
    {
        target.draw(startScreen);
        target.draw(startButton);
        target.draw(play);
    }
}


