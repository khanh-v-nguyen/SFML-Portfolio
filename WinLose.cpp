//
// Created by Khanh Nguyen on 12/14/22.
//

#include "WinLose.h"
//for drawing you win or you lose, decrementing hearts, displaying splash screen
sf::Texture WinLose::heartsTexture;
sf::Font WinLose::font;

WinLose::WinLose()
{
    setUpHearts();
    setUpBox();
    setUpText();
    newBox.enableStates(HIDDEN);
}

void WinLose::setUpHearts()
{
    heartsTexture.loadFromFile("images/pixelHeart.png");

    for(int i = 0; i < 3; i++)
    {
        hearts.push_back(sf::RectangleShape());
        hearts[i].setSize({75,75});
        hearts[i].setTexture(&heartsTexture);
    }
    Position::left(hearts[0], hearts[1]);
    Position::left(hearts[1], hearts[2]);
}

void WinLose::eventHandler(Player &player, sf::RenderWindow &window, sf::Event &event) //checks for collisions
{
    splash.eventHandler(window, event);
    if(CarRow::collideCount != CarRow::temp)
    {
        if(CarRow::collideCount <= 0)
        {
            //CarRow::collideCount = 3;
            newBox.disableStates(HIDDEN);
            winOrLose.setString("YOU LOST");
        }
        //CarRow::temp = CarRow::collideCount;
    }

    if(player.getPosition().y < 100)
    {
        player.setPosition({1920/2,1080 - 100});
        newBox.disableStates(HIDDEN);
        winOrLose.setString("YOU WIN!");
    }

    if(MouseEvents::isHovered(playAgain, window))
    {
        playAgain.setFillColor(sf::Color::Green);
    }
    else
    {
        playAgain.setFillColor(sf::Color::White);
    }

    if(MouseEvents::isHovered(exit, window))
    {
        exit.setFillColor(sf::Color::Green);
    }
    else
    {
        exit.setFillColor(sf::Color::White);
    }

    if(MouseEvents::isClicked(playAgain, window))
    {
        newBox.enableStates(HIDDEN);
        CarRow::collideCount = 3;
        CarRow::temp = CarRow::collideCount;
    }

    if(MouseEvents::isClicked(exit, window))
    {
        newBox.enableStates(HIDDEN);//bc of hearts equaling 0
        splash.disableStates(HIDDEN);
        CarRow::collideCount = 3;
        //splash.disableStates(HIDDEN);
        //splash.splashSize = {1920, 1080};
    }

}

void WinLose::setUpBox()
{
    winLoseBox.setSize({600,400});
    winLoseBox.setFillColor(sf::Color::Black);

    sf::FloatRect w = winLoseBox.getGlobalBounds();

    winLoseBox.setPosition({1920 / 2 - w.width /2 , 1080 /2 -w.height /2});
}

void WinLose::setUpText()
{
    sf::FloatRect w = winLoseBox.getGlobalBounds();

    font.loadFromFile("PIXELADE.TTF");

    playAgain.setFont(font);
    playAgain.setString("PLAY AGAIN");
    playAgain.setCharacterSize(50);

    sf::FloatRect p = playAgain.getGlobalBounds();
    playAgain.setPosition(w.left + w.width /2 - p.width /2, w.top + w.height /2);

    exit.setFont(font);
    exit.setString("Exit");
    exit.setCharacterSize(50);
    Position::centerBottom(playAgain, exit);

    sf::FloatRect n = newBox.getGlobalBounds();
    newBox.setPosition({1920 / 2 - n.width /2 , 1080 /2 -n.height /2});

    sf::FloatRect n1 = newBox.getGlobalBounds();

    winOrLose.setFont(font);
    winOrLose.setCharacterSize(100);
    winOrLose.setString("YOU LOST");
    sf::FloatRect win = winOrLose.getGlobalBounds();

    winOrLose.setPosition({n1.left + n1.width/2 - win.width/2, n1.top + n1.height/3 - win.height/2});

}

void WinLose::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(int i = 0; i < CarRow::collideCount; i++)
    {
        target.draw(hearts[i]);
    }
    //target.draw(winLoseBox);

    if(!newBox.checkStates(HIDDEN))
    {
        target.draw(newBox);
        target.draw(winOrLose);
        target.draw(playAgain);
        target.draw(exit);
    }

    if(!splash.checkStates(HIDDEN))
    {
        target.draw(splash);
    }
}


