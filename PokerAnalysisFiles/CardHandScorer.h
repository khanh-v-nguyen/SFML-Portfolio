//
// Created by Khanh Nguyen on 11/4/22.
//

#ifndef SFML_TEMPLATE_CARDHANDSCORER_H
#define SFML_TEMPLATE_CARDHANDSCORER_H
#include "CardHand.h"
#include "PokerScore.h"

class CardHandScorer : public CardHand, PokerScore
{
public:
    CardHandScorer();
    CardHandScorer(CardHand hand);
    static PokerScore scorePokerHand(CardHand playerHand);
    static void outputScores();

    static bool isRoyalFlush(CardHand playerHand);
    static bool isStraightFlush(CardHand hand);
    static bool isFourOfAKind(CardHand hand);
    static bool isFullHouse(CardHand hand);
    static bool isFlush(CardHand hand);
    static bool isStraight(CardHand hand);
    static bool isThreeOfAKind(CardHand hand);
    static bool isTwoPair(CardHand hand);
    static bool isOnePair(CardHand hand);
    static bool isHighCard(CardHand hand);
};

#endif //SFML_TEMPLATE_CARDHANDSCORER_H
