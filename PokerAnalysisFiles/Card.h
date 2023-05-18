//
// Created by Khanh Nguyen on 11/2/22.
//

#ifndef SFML_TEMPLATE_CARD_H
#define SFML_TEMPLATE_CARD_H
#include "rankEnum.h"
#include "suitEnum.h"
#include <iostream>
#include <vector>


class Card
{
public:
    Card();
    Card(rankEnum, suitEnum);
    rankEnum rank;
    suitEnum suit;

//    static std::string rankToString(rankEnum rank); //paired with commented out below
    std::string rankToString(rankEnum rank);
    std::string suitToString(suitEnum suit);
//    friend std::ostream& operator << (std::ostream& outs, const Card &rhs);
    friend std::ostream& operator << (std::ostream& outs,Card rhs);
    friend bool operator < (const Card &lhs, const Card &rhs);


};

#endif //SFML_TEMPLATE_CARD_H
