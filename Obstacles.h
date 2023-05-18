//
// Created by Khanh Nguyen on 12/5/22.
//

#ifndef SFML_TEMPLATE_OBSTACLES_H
#define SFML_TEMPLATE_OBSTACLES_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ObstacleType.h"
class Obstacles : public sf::Drawable
{
private:
    //void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    Obstacles();
    Obstacles(ObstacleType type);
    Obstacles(sf::Vector2f speed);
    void init();
    sf::Sprite car;
    ObstacleType type;
    float speed;

    std::string typeToString();
    void fly();
    void fly(float speed);
    sf::Vector2f getObstaclePosition();
    void collide(Player &player1);
    void collide(Player &player1, Player &player2);
    void setUpTexture();
    void setPosition(float x, float y);
    void setPosition(sf::Vector2f pos);

    static sf::Texture texture;
    static sf::Texture logTexture;
    static sf::Texture lilyTexture;


    sf::FloatRect getGlobalBounds();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};

#endif //SFML_TEMPLATE_OBSTACLES_H
