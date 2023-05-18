//
// Created by Khanh Nguyen on 12/10/22.
//

#include "CarRow.h"

int CarRow::collideCount =3;
int CarRow::temp = 3;

CarRow::CarRow()
{
    setUpRow();
}

CarRow::CarRow(float carSpeed) : type(CAR)
{
    this -> carSpeed = carSpeed;
    setUpRow();
}

CarRow::CarRow(float carSpeed, sf::Vector2f carRowPosition)
{
    this -> carSpeed = carSpeed;
    this -> carRowPosition = carRowPosition;
    setUpRow();
}

CarRow::CarRow(float carSpeed, sf::Vector2f carRowPosition, ObstacleType type)
{
    this -> type = type;
    this -> carSpeed = carSpeed;
    this -> carRowPosition = carRowPosition;
    setUpRow();
}

void CarRow::setUpRow()
{
    int random = rand() % 500; //position difference in one car row
    for(int i = 0; i < 4; i++)
    {
        carRow.push_back(Obstacles(type));
    }

    carRow[0].setPosition(carRowPosition);

    for(int i = 1; i < 4; i++)
    {
        carRow[i].setPosition(carRow[i-1].getObstaclePosition().x - random,carRow[i-1].getObstaclePosition().y);
    }
}

void CarRow::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(int i = 0; i < carRow.size(); i++)
    {
        target.draw(carRow[i]);
    }
}

void CarRow::move()
{
    for(int i = 0; i < carRow.size(); i++)
    {
        carRow[i].fly(carSpeed);
    }
}

sf::FloatRect CarRow::getGlobalBounds()
{
    sf::FloatRect b  = carRow[0].getGlobalBounds();

    return b;
}


void CarRow::setPosition(sf::Vector2f pos)
{
    carRow[0].setPosition(pos);

    for(int i = 1; i < carRow.size(); i++)
    {
        carRow[i].setPosition(carRow[i-1].getObstaclePosition().x - 500,carRow[i-1].getObstaclePosition().y);
    }
}

bool CarRow::collide(Player &player1)
{
    sf::FloatRect p1 = player1.getGlobalBounds();

    for(int i = 0; i < carRow.size(); i++)
    {
        sf::FloatRect obstacle = carRow[i].getGlobalBounds();

        if(obstacle.intersects(p1) && (type == LOG || type == LILYPAD))
        {
            player1.push(carSpeed);
            //std::cout << "log touched";
        }

        if(obstacle.intersects(p1) && type == CAR || p1.left > 1920 + p1.width || p1.left < 0)
        {
            player1.setPosition({1920/2,1080 - 100});


            CarRow::temp = CarRow::collideCount; //using to compare if lives have changed in map class
            CarRow::collideCount -=1;
        }
    }
    return false;
}

void CarRow::eventHandler()
{
    move();
    //collide(Player player1);
}

