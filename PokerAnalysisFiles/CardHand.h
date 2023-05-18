//
// Created by Khanh Nguyen on 11/4/22.
//

#ifndef SFML_TEMPLATE_CARDHAND_H
#define SFML_TEMPLATE_CARDHAND_H
#include <algorithm>
#include "Deck.h"

class CardHand
{
public:
    CardHand();
    void addCard(Card dealtCard);
    Card operator [] (int i);
    std::vector<rankEnum> allRanks;
    int rankCounter = 1; //counts how many same ranks (dupes)
    int pairCounter = 0;

    Card getCard(int i);
    Card getCardRank(int i);
    Card getCardSuit(int i);

    void sortRanks();
    void countSameRanks();
    void countPairs();
    bool isSequence();
    bool isSameSuit();
    bool isSameFiveRanks();

    friend std::ostream& operator << (std::ostream& outs, CardHand hand);

private:
    std::vector<Card> hand;
};

#endif //SFML_TEMPLATE_CARDHAND_H
