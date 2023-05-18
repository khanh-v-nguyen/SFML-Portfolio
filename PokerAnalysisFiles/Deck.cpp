//
// Created by Khanh Nguyen on 11/2/22.
//
#include "Deck.h"

Deck::Deck()
{
    fillDeck();
    shuffle();
    //printDeck();
}
void Deck::fillDeck()
{
    int deckPosition = 0;
    for(int i = 0; i < numSuits; i++)
        for(int j = 0 ; j < numRanks; j++)
            deck[deckPosition++] = Card(static_cast<rankEnum>(j+1),static_cast<suitEnum>(i+1));
}

void Deck::printDeck()
{
    for(int i = 0; i < DECK_SIZE; i++)
    {
        std::cout << i + 1 << ": " << rankToString(deck[i].rank) << " of " << suitToString(deck[i].suit) << std::endl;
    }
}

std::ostream& operator << (std::ostream& outs, Deck deck)
{
    for(int i = 0; i < 52; i++)
        outs << i + 1 << ": " << deck.rankToString(deck[i].rank) << " of " << deck.suitToString(deck[i].suit) << std::endl;
    return outs;
}


Card Deck::operator[] (unsigned int index) const
{
    return *(deck + index);
}

void Deck::shuffle()
{
    Card tempCard;
    int allRandNums[52];
    int randNum;

//    for(int i = 0; i < DECK_SIZE; ++i)
//    {
//        randNum = rand() % 52;
//        if(allRandNums[i] != allRandNums[i-1])
//        {
//            allRandNums[i] = randNum;
//        }
//    }

    for(int i = 0; i < 52; i++)
    {
        randNum = rand() % 52;
        tempCard = deck[i];
        deck[i] = deck[randNum];
        deck[randNum] = tempCard;
    }
}

Card Deck::dealCard()
{
    return deck[cardIndex++];
}

