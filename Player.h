//
// Created by Khanh Nguyen on 12/4/22.
//

#ifndef SFML_TEMPLATE_PLAYER_H
#define SFML_TEMPLATE_PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Player : public sf::Drawable
{
public:
    Player();
    Player(int rows, int cols);
    void animate();

    sf::Clock clock;
    sf::IntRect intRect;
    sf::Sprite player1;
    sf::Sprite player2;
    static sf::Texture playerTexture;

    void setUpSprite();
    void setUpTexture();
    std::string textureToString();
    void init();
    void move(float x, float y);
    void push(float speed); //log or lilypad pushing player
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f vec);
    sf::FloatRect getGlobalBounds();

    void reachTop();


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};

#endif //SFML_TEMPLATE_PLAYER_H
