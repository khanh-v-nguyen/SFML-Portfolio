//
// Created by Khanh Nguyen on 11/4/22.
//
#include "CardHandScorer.h"
#include <algorithm>
#include <iostream>


CardHandScorer::CardHandScorer()
{

}

PokerScore CardHandScorer::scorePokerHand(CardHand hand)
{
    PokerScore p;

    if(isRoyalFlush(hand))
    {
        p += ROYAL_FLUSH;
        p +=STRAIGHT_FLUSH;
        p +=THREE_OF_A_KIND;
        p += HIGH_CARD;

        p.RFCOUNTER++;
        p.SFCOUNTER++;
        p.TCOUNTER++;
        p.HCCOUNTER++;

        //p.scoreCounter[ROYAL_FLUSH]++;
    }
    else if(isStraightFlush(hand)) //sequence exists, sameRankSuit == 5;
    {
        p += STRAIGHT_FLUSH;
        p += FLUSH;
        p += FLUSH;
        p += HIGH_CARD;

        p.SFCOUNTER++;
        p.FCOUNTER++;
        p.HCCOUNTER++;

    }
    else if(isFourOfAKind(hand))
    {
        p += FOUR_OF_A_KIND;
        p += THREE_OF_A_KIND;
        p += ONE_PAIR;
        p += HIGH_CARD;

        p.FOAKCOUNTER++;
        p.TCOUNTER++;
        p.OPCOUNTER++;
        p.HCCOUNTER++;
    }
    else if(isFullHouse(hand))
    {
        p += FULL_HOUSE;
        p += THREE_OF_A_KIND;
        p += TWO_PAIR;
        p += HIGH_CARD;

        p.FHCOUNTER++;
        p.TCOUNTER++;
        p.HCCOUNTER++;
        p.OPCOUNTER++;
    }
    else if(isFlush(hand)) // FLUSH
    {
        p += FLUSH;
        p += HIGH_CARD;

        p.FCOUNTER++;
        p.HCCOUNTER++;
    }
    else if(isStraight(hand)) // STRAIGHT
    {
        p += STRAIGHT;
        p += HIGH_CARD;

        p.SCOUNTER++;
        p.HCCOUNTER++;
    }
    else if(isThreeOfAKind(hand)) // isThreeOfAKind;
    {
        p += THREE_OF_A_KIND;
        p += ONE_PAIR;
        p += HIGH_CARD;

        p.TCOUNTER++;
        p.OPCOUNTER++;
        p.HCCOUNTER++;

    }
    else if(isTwoPair(hand)) // twoPair;
    {
        p += TWO_PAIR;
        p += ONE_PAIR;
        p += HIGH_CARD;

        p.TPCOUNTER++;
        p.OPCOUNTER++;
        p.HCCOUNTER++;
    }
    else if(isOnePair(hand)) // ; onepair
    {
        p += ONE_PAIR;
        p += HIGH_CARD;

        p.OPCOUNTER++;
        p.HCCOUNTER++;

    }
    else // high card
    {
        p += HIGH_CARD;
        p.HCCOUNTER++;
    }
    return p;
}

//
bool CardHandScorer::isRoyalFlush(CardHand hand)
{
    rankEnum royalEnums[5] = {ACE, TEN, JACK, QUEEN, KING};
    for(int i = 0; i < 5; i++)
    {
        if(hand[i].rank == royalEnums[i] && hand.isSameSuit() == true)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool CardHandScorer::isStraightFlush(CardHand hand)
{
    if(hand.isSequence() == true && hand.isSameSuit() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CardHandScorer::isFourOfAKind(CardHand hand)
{
    if(hand.rankCounter == 4 || hand.isSameFiveRanks() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CardHandScorer::isFullHouse(CardHand hand)
{
    if(isThreeOfAKind(hand) && hand.rankCounter == 3 && hand.pairCounter == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CardHandScorer::isFlush(CardHand hand)
{
    if(hand.isSameSuit() == true) // samesuit
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CardHandScorer::isStraight(CardHand hand)
{
    if(hand.isSequence() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CardHandScorer::isThreeOfAKind(CardHand hand)
{
    if(hand.rankCounter == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CardHandScorer::isTwoPair(CardHand hand)
{

    if(hand.pairCounter == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CardHandScorer::isOnePair(CardHand hand)
{
    if(hand.pairCounter == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CardHandScorer::isHighCard(CardHand hand)
{
    return true;
}


void CardHandScorer::outputScores()
{
    std::cout << "Royal Flush: " << PokerScore::RFCOUNTER << std::endl;
    std::cout << "Straight Flush: " << PokerScore::SFCOUNTER <<std::endl;
    std::cout << "Four of a kind: "<< PokerScore::FOAKCOUNTER << std::endl;
    std::cout << "Full House: "<< PokerScore::FHCOUNTER <<std::endl;
    std::cout << "Flush: "<< PokerScore::FCOUNTER <<std::endl;
    std::cout << "Straight: "<< PokerScore::SCOUNTER <<std::endl;
    std::cout << "Three of a kind "<< PokerScore::TCOUNTER <<std::endl;
    std::cout << "Two pair: "<< PokerScore::TPCOUNTER <<std::endl;
    std::cout << "One Pair: "<< PokerScore::OPCOUNTER << std::endl;
    std::cout << "High card: "<< PokerScore::HCCOUNTER <<std::endl;
}