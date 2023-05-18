//
// Created by Khanh Nguyen on 12/14/22.
//
#include "PongBall.h"

PongBall::PongBall()
{

}


void PongBall::setVelocity(const sf:: Vector2f &velocity)
{
    this -> velocity = velocity;
}

void PongBall::bounce(const sf::Vector2u& windowSize)
{
    sf::FloatRect b = getGlobalBounds();
    if(b.top + b.height > windowSize.y || b.top <= 0)
    {
        velocity.y = -velocity.y;
    }

    if(b.left + b.width > windowSize.x || b.left <= 0)
    {
        velocity.x = -velocity.x;
    }
    sf::CircleShape::move(velocity);

    scoreTrack(windowSize);
}


void PongBall::scoreTrack(const sf::Vector2u& windowSize)
{
    //std::cout << pointRed << std::endl;
    //std::cout << pointBlue << std::endl;

    sf::FloatRect c = getGlobalBounds();

    if(c.left <= 0)
    {
        pointBlue += 1;
    }
    if(c.left + c.width >= windowSize.x)
    {
        pointRed += 1;
    }
}