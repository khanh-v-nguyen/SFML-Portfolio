//
// Created by Khanh Nguyen on 12/13/22.
//

#ifndef SFML_TEMPLATE_PORTFOLIOSCREEN_H
#define SFML_TEMPLATE_PORTFOLIOSCREEN_H
#include <SFML/Graphics.hpp>
#include "GameEnum.h"
#include "MouseEvents.h"
#include "CrossyRoad.h"
#include "GreenCircleFiles/GreenCircle.h"
#include "TopHatGuyFiles/TophatGuyRun.h"
#include "PongFiles/PongBallRun.h"
#include "PokerAnalysisFiles/PokerAnalysisRun.h"

class PortfolioScreen : public sf::Drawable
{
public:
    PortfolioScreen();
    PortfolioScreen(GameEnum gameType);


    GameEnum gameType;
    sf::RectangleShape gamePic;
    sf::RectangleShape triangleLeft;
    sf::RectangleShape triangleRight;
    sf::Text title;

    static sf::Texture coverTexture;
    static sf::Texture crossyTexture;
    static sf::Texture circleTexture;
    static sf::Texture pongTexture;
    static sf::Texture topHatGuyTexture;
    static sf::Texture pokerTexture;


    static sf::Texture triangleTexture;
    static sf::Texture triangleLeftTexture;


    static sf::Font font;

    void init();
    void setUpTexture();
    void setUpPic();
    void setUpTitle();
    void setUpArrows();
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    std::string typeToString();
    const sf::Texture getTexture() const;

    void gamePressed();


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif //SFML_TEMPLATE_PORTFOLIOSCREEN_H
