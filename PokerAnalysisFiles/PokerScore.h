//
// Created by Khanh Nguyen on 11/6/22.
//

#ifndef SFML_TEMPLATE_POKERSCORE_H
#define SFML_TEMPLATE_POKERSCORE_H
#include <vector>

class PokerScore
{
public:
    PokerScore();

    enum Scores{

        ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

        STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

        FOUR_OF_A_KIND, //four cards of the same ranking

        FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

        FLUSH, //five cards of the same suit

        STRAIGHT, //five cards in consecutive ranking

        THREE_OF_A_KIND , //three cards of the same rank

        TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

        ONE_PAIR, //two cards of the same rank

        HIGH_CARD,//highest card in the player’s hand

    };

    static int RFCOUNTER;
    static int SFCOUNTER;
    static int FOAKCOUNTER;
    static int FHCOUNTER;
    static int FCOUNTER;
    static int SCOUNTER;
    static int TCOUNTER;
    static int TPCOUNTER;
    static int OPCOUNTER;
    static int HCCOUNTER;

    std::vector<Scores> scores;

    void operator+=(const Scores& score);

    friend bool operator==(const PokerScore& p, Scores score);

    int size();
    Scores& operator[](unsigned int index);
    static std::string scoreToString(Scores score);

    friend std::ostream& operator << (std::ostream& outs, const PokerScore & rhs);

    void addToCounters();

    int counterArray[10];

};

#endif //SFML_TEMPLATE_POKERSCORE_H
