#include "CrossyRoad.h"
#include "PortfolioScreen.h"
#include <vector>
#include "GreenCircleFiles/GreenCircle.h"

#include "Portfolio.h"

int main() {

    //CrossyRoad game1;
    Portfolio finalPortfolio;
    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Khanh's Portfolio");

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            finalPortfolio.eventHandler(window);
        }
        window.clear(sf::Color::Black);
        window.draw(finalPortfolio);

        window.display();
    }


}
