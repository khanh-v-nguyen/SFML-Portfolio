//
// Created by Khanh Nguyen on 12/14/22.
//

#ifndef SFML_TEMPLATE_PONGPADDLE_H
#define SFML_TEMPLATE_PONGPADDLE_H

#include "PongBall.h"
class PongPaddle : public sf::RectangleShape
{
public:
    PongPaddle();
    void jump(const sf::Vector2u& windowSize);
    void jump2(const sf::Vector2u& windowSize);

    sf::Vector2f paddleVelocity;
    void collide(PongBall &ball, const sf::Vector2u& windowSize);

};

#endif //SFML_TEMPLATE_PONGPADDLE_H
