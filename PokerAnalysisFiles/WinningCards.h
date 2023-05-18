//
// Created by Khanh Nguyen on 11/14/22.
//

#ifndef SFML_TEMPLATE_WINNINGCARDS_H
#define SFML_TEMPLATE_WINNINGCARDS_H
#include "DrawCard.h"
#include "DisplayCard.h"
#include "DisplayStats.h"

#include <SFML/Graphics.hpp>


class WinningCards : public DrawCard
{
public:

    static void printRY(sf::RenderWindow & window);
    static void printSF(sf::RenderWindow & window);
    static void printFOAK(sf::RenderWindow & window);
    static void printFH(sf::RenderWindow & window);
    static void printF(sf::RenderWindow & window);
    static void printS(sf::RenderWindow & window);
    static void printT(sf::RenderWindow & window);
    static void printTP(sf::RenderWindow & window);
    static void printOP(sf::RenderWindow & window);
    static void printHC(sf::RenderWindow & window);


};

#endif //SFML_TEMPLATE_WINNINGCARDS_H
