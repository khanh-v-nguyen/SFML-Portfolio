//
// Created by Khanh Nguyen on 11/14/22.
//
#include "DisplayStats.h"
sf::Font DisplayStats::font;

DisplayStats::DisplayStats(std::string score, int pokerScore, sf::Vector2f position)
{
    this -> name = score;
    this -> counterName = pokerScore;
    setUpScore();
    setUpStat();
    scoreName.setPosition(position);
    sf::FloatRect s = scoreName.getGlobalBounds();
    stat.setPosition({s.left + s.width, s.top - s.height/4});

}

void DisplayStats::draw(sf::RenderTarget& Window, sf::RenderStates states) const
{
    Window.draw(scoreName);
    Window.draw(stat);

}
void DisplayStats::setUpScore()
{
    if(!font.loadFromFile("/Users/khanh/CLionProjects/PokerAnalysis/fonts/OpenSans-Bold.ttf"))
        exit(20);
    scoreName.setFont(font);
    scoreName.setColor(sf::Color::Red);
    scoreName.setCharacterSize(50);
    scoreName.setString(name);
}

void DisplayStats::setUpStat()
{
    stringStat = std::to_string(PokerScore::HCCOUNTER / counterName);
    if(!font.loadFromFile("/Users/khanh/CLionProjects/PokerAnalysis/fonts/OpenSans-Bold.ttf"))
        exit(20);
    stat.setFont(font);
    stat.setColor(sf::Color::Red);
    stat.setCharacterSize(50);
    stat.setString(stringStat);
}

