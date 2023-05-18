//
// Created by Khanh Nguyen on 11/14/22.
//

#ifndef SFML_TEMPLATE_DISPLAYSTATS_H
#define SFML_TEMPLATE_DISPLAYSTATS_H
#include <SFML/Graphics.hpp>
#include "PokerScore.h"


class DisplayStats : public sf::Drawable
{
public:
    DisplayStats(std::string score, int pokerScore, sf::Vector2f position);
    sf::Text scoreName;
    sf::Text stat;
    void setUpScore();
    void setUpStat();
    static sf::Font font;
    void draw(sf::RenderTarget& Window, sf::RenderStates states) const;
    std::string name;
    std::string stringStat;
    int counterName;


};

#endif //SFML_TEMPLATE_DISPLAYSTATS_H
