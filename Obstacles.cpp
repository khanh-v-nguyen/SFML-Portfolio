//
// Created by Khanh Nguyen on 12/5/22.
//

#include "Obstacles.h"

sf::Texture Obstacles::texture;
sf::Texture Obstacles::logTexture;
sf::Texture Obstacles::lilyTexture;

Obstacles::Obstacles()
{
    init();
}

Obstacles::Obstacles(ObstacleType type)
{
    this -> type = type;
    init();
}

void Obstacles::init()
{
    sf::FloatRect c = car.getGlobalBounds();
    car.setPosition({-2 *c.width,100});
    setUpTexture();
}

void Obstacles::fly() //default fly function
{
    sf::FloatRect o = car.getGlobalBounds();

    if(o.left >= 1920 + o.width)
    {
        std::cout << "hit window";
        car.setPosition(- o.width,o.top);
        //CircleShape::move({-10,0});
    }
    else
    {
        car.move({0.15,0});
    }
}

void Obstacles::fly(float speed) //making obstacles move, if reach end of screen then loop around
{
    sf::FloatRect o = car.getGlobalBounds();

    this -> speed = speed;

    if(o.left >= 1920 + o.width)
    {
        car.setPosition(- o.width,o.top);
    }
    else
    {
        car.move({speed,0});
    }

}

sf::Vector2f Obstacles::getObstaclePosition()
{
    return car.getPosition();
}


void Obstacles::collide(Player &player1)
{
    sf::FloatRect p1 = player1.getGlobalBounds();

    sf::FloatRect obstacle = car.getGlobalBounds();

    if(obstacle.intersects(p1))
    {
        player1.setPosition({100,1080});
    }

//    if(obstacle.intersects(p1) && ObstacleType == LOG)
//    {
//        player1.move({0,30});
//    }
}

//for multiplayer mode
//void Obstacles::collide(Player &player1, Player &player2)
//{
//    sf::FloatRect p1 = player1.getGlobalBounds();
//    sf::FloatRect p2 = player2.getGlobalBounds();
//
//    sf::FloatRect o = car.getGlobalBounds();
//
//    if(o.intersects(p1))
//    {
//        player1.setPosition({100,1080});
//    }
//    else if(o.intersects(p1))
//    {
//        player2.setPosition({800,1080});
//    }
//}

void Obstacles::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(car);
}


void Obstacles::setPosition(float x, float y)
{
    car.setPosition(x,y);
    //car2.setPosition(2*x, 2*y);
}

void Obstacles::setUpTexture()
{
    if(!texture.loadFromFile(typeToString()))
    {
        exit(20);
    }
    car.setTexture(texture);

    if(type==LOG)
    {
        if(!logTexture.loadFromFile(typeToString()))
        {
            exit(21);
        }
        car.setTexture(logTexture);
    }

    if(type==LILYPAD)
    {
        if(!lilyTexture.loadFromFile(typeToString()))
        {
            exit(22);
        }
        car.setTexture(lilyTexture);
    }
}

std::string Obstacles::typeToString()
{
    switch(type)
    {
        case 1: return "images/blueCar.png";
        case 2: return "images/brown_log.png";
        case 3: return "images/lilypad.png";
    }
}

sf::FloatRect Obstacles::getGlobalBounds()
{
    return car.getGlobalBounds();
}

void Obstacles::setPosition(sf::Vector2f pos)
{
    car.setPosition(pos);
}








