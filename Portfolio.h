//
// Created by Khanh Nguyen on 12/13/22.
//

#ifndef SFML_TEMPLATE_PORTFOLIO_H
#define SFML_TEMPLATE_PORTFOLIO_H
#include "PortfolioScreen.h"
#include <vector>

class Portfolio : public sf::Drawable
{
public:
    Portfolio();
    void addScreen();
    void eventHandler(sf::RenderWindow &window);
    std::vector<PortfolioScreen>::iterator iter;
    std::vector<PortfolioScreen> myPortfolio;

    sf::RectangleShape background;
    static sf::Texture backgroundTexture;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};

#endif //SFML_TEMPLATE_PORTFOLIO_H
