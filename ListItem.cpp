//
// Created by Khanh Nguyen on 12/7/22.
//
#include "ListItem.h"

sf::Font ListItem::font;
sf::Texture ListItem::listTexture;


ListItem::ListItem() : buttonName(""), boxSize({1000,800})
{
    setUpBox();
    setUpText();
}

ListItem::ListItem(std::string buttonName, sf::Vector2f boxSize)
{

}

ListItem::ListItem(std::string texture) : boxSize({1920, 100}), position({0, 1080/2})
{
    setUpBox();
    setUpText();
    listTexture.loadFromFile(texture);
    box.setTexture(&listTexture);
}

ListItem::ListItem(std::string buttonName, sf::Vector2f boxSize, sf::Vector2f position)
{
    this -> boxSize = boxSize;
    this -> position = position;
    this -> buttonName = buttonName;
    setUpBox();
    setUpText();
}

void ListItem::setUpBox()
{
    box.setSize({boxSize});
    box.setFillColor(sf::Color::Black);
    box.setPosition(position);
    box.setOutlineColor(sf::Color::Red);
    box.setOutlineThickness(2);
}

void ListItem::setUpText()
{
    sf::FloatRect b = box.getGlobalBounds();

    if(!font.loadFromFile("PIXELADE.TTF"))
        exit(20);

    buttonText.setCharacterSize(50);
    buttonText.setFont(font);
    buttonText.setString(buttonName);
    buttonText.setFillColor(sf::Color::White);

    sf::FloatRect t = buttonText.getGlobalBounds();

    buttonText.setPosition(b.left + b.width/2 - t.width/2, b.top + b.height/2 - t.height/2);
}

void ListItem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(box);
    target.draw(buttonText);
}

sf::FloatRect ListItem::getGlobalBounds()
{
    return box.getGlobalBounds();
}

void ListItem::setPosition(sf::Vector2f pos)
{
    box.setPosition(pos);

    sf::FloatRect b = box.getGlobalBounds();
    buttonText.setPosition(b.left + b.width/2, b.top + b.height/2);

}
