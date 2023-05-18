//
// Created by Khanh Nguyen on 11/2/22.
//

#ifndef SFML_TEMPLATE_DECK_H
#define SFML_TEMPLATE_DECK_H
#include "Card.h"
class Deck : public Card
{
public:
    const int numRanks = 13;
    const int numSuits = 4;
    Deck();
    Card deck[52];
    const int DECK_SIZE = 52;
    void fillDeck();
    void printDeck();
    Card operator[] (unsigned int index) const;
    void shuffle();
    Card dealCard();
    int cardIndex = 0;
    friend std::ostream& operator << (std::ostream& outs, Deck deck);


};

#endif //SFML_TEMPLATE_DECK_H
