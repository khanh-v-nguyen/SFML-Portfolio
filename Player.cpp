//
// Created by Khanh Nguyen on 12/4/22.
//
#include "Player.h"

sf::Texture Player::playerTexture;

Player::Player() : Player(4,4)
{
    init();
}


void Player::init()
{
    setUpSprite();
    setUpTexture();
}

void Player::setUpSprite()
{
    sf::IntRect cat = {100,0,100,300};
    player1.setTextureRect(cat);
    player1.setPosition(100,1080);

    player1.setPosition({1920/2,1080 - 100});
}

void Player::setUpTexture()
{
    if(!playerTexture.loadFromFile("ash.png"))
    {
        exit(21);
    }
    player1.setTexture(playerTexture);
    player2.setTexture(playerTexture);

}

std::string Player::textureToString()
{
    return "blank";
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(player1);
    //target.draw(player2);
}

void Player::push(float speed)
{
    player1.move({speed,0}); //passing in speed of lilypad/log so player can be pushed at same speed
}

void Player::move(float x, float y)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player1.move(0,-0.2);
        //player1.setPosition({getPosition().x, getPosition().y - 5});
        intRect.top = 3 * intRect.height;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player1.move(-0.2,0);
        intRect.top = intRect.height;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player1.move(0,0.2);
        intRect.top = 0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player1.move(0.2,0);
        intRect.top = 2 * intRect.height;
    }
}

sf::Vector2f Player::getPosition()
{
    return player1.getPosition();
}

void Player::setPosition(sf::Vector2f vec)
{
    player1.setPosition(vec);
}

sf::FloatRect Player::getGlobalBounds()
{
    return player1.getGlobalBounds();
}

void Player::reachTop()
{
    if(player1.getPosition().y <= 0)
    {
        std::cout << "top is hit, player wins";
        //draw a winning screen, play again (reset rungame)
    }
}

void Player::animate()
{

    if(clock.getElapsedTime().asSeconds() > 0.250)
    {
        if(intRect.left + (2 * intRect.width) > playerTexture.getSize().x) // checking to see we're going beyond the length of texture pic, if it does go back to 0 position, loop for all 4 rows
            intRect.left = 0;
        else
            intRect.left += intRect.width; //moving the box that cuts of the texture
        clock.restart();
    }

    player1.setTextureRect(intRect); //takes and int rect, sets the bounds of the texture

}

Player::Player(int rows, int cols)
{
    setUpTexture();
    intRect.width = playerTexture.getSize().x / cols; //our sprite is a child of smth that alr had getSize.
    intRect.height = playerTexture.getSize().y / rows; //our sprite is a child of smth that alr had getSize.
    intRect.top = 0;
    intRect.left = 0;
    player1.setTextureRect(intRect);
}



