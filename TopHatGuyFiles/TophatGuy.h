//
// Created by Khanh Nguyen on 12/14/22.
//

#ifndef SFML_TEMPLATE_TOPHATGUY_H
#define SFML_TEMPLATE_TOPHATGUY_H

#include <SFML/Graphics.hpp>

class TophatGuy : public sf::Drawable, public sf::Transformable
{
public:
    TophatGuy();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //in order for something to be drawable it must have this function
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);

private:
    sf::RectangleShape top, brim;
    sf::CircleShape face;
};

#endif //SFML_TEMPLATE_TOPHATGUY_H
