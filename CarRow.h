//
// Created by Khanh Nguyen on 12/10/22.
//

#ifndef SFML_TEMPLATE_CARROW_H
#define SFML_TEMPLATE_CARROW_H
#include <vector>
#include "Obstacles.h"


class CarRow : public sf::Drawable
{
public:
    CarRow();
    CarRow(float carSpeed);
    CarRow(float carSpeed, sf::Vector2f carRowPosition);
    CarRow(float carSpeed, sf::Vector2f carRowPosition, ObstacleType type);

    float carSpeed;
    sf::Vector2f carRowPosition;
    ObstacleType type;

    std::vector<Obstacles> carRow;
    void setUpRow();
    void move();
    bool collide(Player &player1);
    void setPosition(sf::Vector2f pos);
    void eventHandler();
    sf::FloatRect getGlobalBounds();

    static int collideCount;
    static int temp;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_CARROW_H
