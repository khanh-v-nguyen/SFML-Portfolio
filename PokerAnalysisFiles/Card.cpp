//
// Created by Khanh Nguyen on 11/2/22.
//
#include "Card.h"

Card::Card()
{
    //std::cout << "hi ";

}

Card::Card(rankEnum rank, suitEnum suit)
{
    this -> suit = suit;
    this -> rank = rank;

}

std::string Card::rankToString(rankEnum rank)
{
    switch(rank)
    {
        case 1: return "ACE";
        case 2: return "TWO";
        case 3: return "THREE";
        case 4: return "FOUR";
        case 5: return "FIVE";
        case 6: return "SIX";
        case 7: return "SEVEN";
        case 8: return "EIGHT";
        case 9: return "NINE";
        case 10: return "TEN";
        case 11: return "JACK";
        case 12: return "QUEEN";
        case 13: return "KING";
    }
}

std::string Card::suitToString(suitEnum suit)
{
    switch(suit)
    {
        case 1: return "CLUBS";
        case 2: return "DIAMONDS";
        case 3: return "HEARTS";
        case 4: return "SPADES";
    }
}


std::ostream& operator << (std::ostream& outs, Card rhs)
{
    return outs << rhs.rankToString(rhs.rank) << " OF " << rhs.suitToString(rhs.suit) << std::endl;
//    rankEnum myRank = rhs.rank;
//    std::string thisCard = Card::rankToString(myRank);
//    outs << thisCard;
//    return outs;
}

bool operator < (const Card &lhs, const Card &rhs)
{
    if(lhs.rank < rhs.rank)
    {
        return true;
    }
    else
        return false;
}



