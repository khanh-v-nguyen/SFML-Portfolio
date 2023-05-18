//
// Created by Khanh Nguyen on 11/6/22.
//

#include "PokerScore.h"
#include <iostream>
int PokerScore::RFCOUNTER = 0;
int PokerScore::SFCOUNTER = 0;
int PokerScore::FOAKCOUNTER = 0;
int PokerScore::FHCOUNTER = 0;
int PokerScore::FCOUNTER = 0;
int PokerScore::SCOUNTER = 0;
int PokerScore::TCOUNTER = 0;
int PokerScore::TPCOUNTER = 0;
int PokerScore::OPCOUNTER = 0;
int PokerScore::HCCOUNTER = 0;


PokerScore::PokerScore()
{

}

void PokerScore::operator+=(const Scores& score)
{
    scores.push_back(score);
}

PokerScore::Scores& PokerScore::operator[](unsigned int index)
{
    return scores[index];
}

std::ostream& operator << (std::ostream& outs, const PokerScore & rhs)
{
    for(int i = 0; i < rhs.scores.size(); i++)
    {
        outs << PokerScore::scoreToString(rhs.scores[i]) << ". ";
    }

    outs << std::endl;
    return outs;
}

std::string PokerScore::scoreToString(Scores score)
{
    switch(score)
    {
        case 0: return "ROYAL FLUSH";
        case 1: return "STRAIGHT FLUSH";
        case 2: return "FOUR OF A KIND";
        case 3: return "FULL HOUSE";
        case 4: return "FLUSH";
        case 5: return "STRAIGHT";
        case 6: return "THREE OF A KIND";
        case 7: return "TWO PAIR";
        case 8: return "ONE PAIR";
        case 9: return "HIGH CARD";
    }

}

void PokerScore::addToCounters()
{
    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[i] == ROYAL_FLUSH)
        {
            counterArray[ROYAL_FLUSH]++;
        }
        else if(scores[i] == FLUSH)
        {
            counterArray[FLUSH]++;
        }
    }
}



