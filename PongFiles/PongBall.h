//
// Created by Khanh Nguyen on 12/14/22.
//

#ifndef SFML_TEMPLATE_PONGBALL_H
#define SFML_TEMPLATE_PONGBALL_H

#include <SFML/Graphics.hpp>


class PongBall : public sf::CircleShape
{
public:
    PongBall();
    void bounce(const sf::RenderWindow& window);
    void bounce(const sf::Vector2u& windowSize);
    void setVelocity(const sf::Vector2f &velocity);

    void scoreTrack(const sf::Vector2u& windowSize);

    sf::Vector2f position;
    sf::Vector2f velocity = {1, 1};

    int pointRed = 0;
    int pointBlue = 0;

};

#endif //SFML_TEMPLATE_PONGBALL_H
