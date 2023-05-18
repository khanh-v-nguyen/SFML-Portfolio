//
// Created by Khanh Nguyen on 12/14/22.
//
#include "PongPaddle.h"


PongPaddle::PongPaddle() : sf::RectangleShape()
{
    paddleVelocity = {0,0};
    //shape yourself like a pong paddle
}

void PongPaddle::jump(const sf::Vector2u& windowSize)
{
    sf::FloatRect b = getGlobalBounds();
    //std::cout << b.top + b.height << std::endl;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && b.top > 0)
    {
        move({0, -0.15});
    }
    else
    {
        move({0, 0});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && b.top + b.height <= windowSize.y)
    {
        move({0, 0.15});
    }
    else
    {
        move({0, 0});
    }
}

void PongPaddle::jump2(const sf::Vector2u& windowSize)
{
    sf::FloatRect b = getGlobalBounds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && b.top > 0)
    {
        move({0, -0.01});
    }
    else
    {
        move({0, 0});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K) && b.top + b.height <= windowSize.y)
    {
        move({0, 0.01});
    }
    else
    {
        move({0, 0});
    }

}


void PongPaddle::collide(PongBall &ball, const sf::Vector2u &windowSize)
{
    sf::FloatRect b = ball.getGlobalBounds();
    sf::FloatRect p = this->getGlobalBounds();

    if(b.intersects(p))
    {
        ball.velocity.x *= -1;
    }
}