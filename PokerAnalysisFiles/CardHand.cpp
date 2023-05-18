//
// Created by Khanh Nguyen on 11/4/22.
//
#include "CardHand.h"
#include <algorithm>


CardHand::CardHand()
{

}

std::ostream& operator << (std::ostream& outs, CardHand hand)
{
    for(int i = 0; i < 5; i++)
    {
        outs << hand[i];
    }
    return outs;
}

void CardHand::addCard(Card dealtCard)
{
    if(hand.size() < 6)
        hand.push_back(dealtCard);
}

Card CardHand::operator [] (int i)
{
    return hand[i];
}

Card CardHand::getCard(int i)
{
    return hand[i];
}

bool CardHand::isSameFiveRanks()
{
    bool fiveCounter;
    for(int i = 0; i < 4; i++)
    {
        if(hand[i].rank == hand[i+1].rank)
        {
            fiveCounter = true;
        }
        else
        {
            return false;
        }
    }
    return fiveCounter;
}

void CardHand::countSameRanks() //bug in rankCount, it adds every time a match is found
{
//    for(int i = 0; i < 5; i++)
//    {
//        if(hand[i].rank == hand[i+1].rank)
//        {
//            rankCounter += 1;
//        }
//    }

//bug with 5 in a row. will print 11
    for (int i = 0; i < 5; ++i) {
        for (int j = i+1; j < 5; ++j) {
            if(hand[i].rank == hand[j].rank)
            {
                rankCounter++;
            }
            else
            {
                i = j;
                break;
            }
        }
    }
    //std::cout << rankCounter;
}

bool CardHand::isSameSuit()
{
    bool sameSuitCounter;
    for(int i = 0; i < 4; i++)
    {
        if(hand[i].suit == hand[i+1].suit)
        {
            sameSuitCounter = true;
        }
        else
        {
            return false;
        }
    }

    return sameSuitCounter;
}

void CardHand::countPairs()
{
    for(int i = 0; i < 5; i++)
    {
        if(hand[i].rank == hand[i+1].rank)
        {
            //std::cout << "i: " << i << std::endl;
            pairCounter++;
            i++;
            //std::cout << pairCounter << std::endl;
        }
    }
    //std::cout << pairCounter;

   if(hand[0].rank == hand[3].rank) //check for 2 diff pairs  1 22 33
   {
       pairCounter -= 1;
   }
}

bool CardHand::isSequence()
{
    bool sequenceCheck;
    for(int i = 0; i < 4; i++)
    {
        if((hand[i].rank) == hand[i+1].rank - 1)
        {
            sequenceCheck = true;
        }
        else
        {
            return false;
        }
    }
    //std::cout << "hi";
    return sequenceCheck;
}

void CardHand::sortRanks()
{
    sort(hand.begin(), hand.end());
}

//void CardHand::sortRanks()
//{
//    for(int i = 0; i < 5; i++)
//    {
//        allRanks.push_back(hand[i].rank);
//    }
//    sort(allRanks.begin(), allRanks.end());
//}




