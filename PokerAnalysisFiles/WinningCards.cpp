//
// Created by Khanh Nguyen on 11/14/22.
//

#include "WinningCards.h"

//for positioning and drawing cards
void WinningCards::printRY(sf::RenderWindow & window)
{

    DisplayCard card1(ACE, CLUBS, {100,100});
    DisplayCard card2(TEN, CLUBS, {card1.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card3(JACK, CLUBS, {card2.xPosition + card1.spacing, card1.yPosition});
    DisplayCard card4(QUEEN, CLUBS, {card3.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card5(QUEEN, CLUBS, {card4.xPosition + card1.spacing,card1.yPosition});

    DisplayStats RoyalFlush("Royal Flush 1/", PokerScore::RFCOUNTER, {card1.xPosition, card1.yPosition - 70});

    window.draw(card1);
    window.draw(card2);
    window.draw(card3);
    window.draw(card4);
    window.draw(card5);
    window.draw(RoyalFlush);

}

void WinningCards::printSF(sf::RenderWindow & window)
{

    DisplayCard card1(FOUR, CLUBS, {100,400});
    DisplayCard card2(FIVE, CLUBS, {card1.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card3(SIX, CLUBS, {card2.xPosition + card1.spacing, card1.yPosition});
    DisplayCard card4(SEVEN, CLUBS, {card3.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card5(EIGHT, CLUBS, {card4.xPosition + card1.spacing,card1.yPosition});

    DisplayStats SF("Straight Flush 1/", PokerScore::SFCOUNTER, {card1.xPosition, card1.yPosition - 70});
    window.draw(card1);
    window.draw(card2);
    window.draw(card3);
    window.draw(card4);
    window.draw(card5);
    window.draw(SF);

}

void WinningCards::printFOAK(sf::RenderWindow & window)
{

    DisplayCard card1(NINE, HEARTS, {100,700});
    DisplayCard card2(NINE, CLUBS, {card1.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card3(NINE, SPADES, {card2.xPosition + card1.spacing, card1.yPosition});
    DisplayCard card4(NINE, CLUBS, {card3.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card5(QUEEN, HEARTS, {card4.xPosition + card1.spacing,card1.yPosition});
    DisplayStats FOAK("Four of a kind 1/", PokerScore::FOAKCOUNTER, {card1.xPosition, card1.yPosition - 70});

    window.draw(card1);
    window.draw(card2);
    window.draw(card3);
    window.draw(card4);
    window.draw(card5);
    window.draw(FOAK);

}

void WinningCards::printFH(sf::RenderWindow & window)
{

    DisplayCard card1(FIVE, HEARTS, {100,1000});
    DisplayCard card2(FIVE, CLUBS, {card1.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card3(FIVE, SPADES, {card2.xPosition + card1.spacing, card1.yPosition});
    DisplayCard card4(QUEEN, CLUBS, {card3.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card5(QUEEN, HEARTS, {card4.xPosition + card1.spacing,card1.yPosition});
    DisplayStats FH("Full house 1/", PokerScore::FHCOUNTER, {card1.xPosition, card1.yPosition - 70});

    window.draw(card1);
    window.draw(card2);
    window.draw(card3);
    window.draw(card4);
    window.draw(card5);
    window.draw(FH);
}

void WinningCards::printF(sf::RenderWindow & window)
{

    DisplayCard card1(NINE, HEARTS, {100,1300});
    DisplayCard card2(ACE, HEARTS, {card1.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card3(SEVEN, HEARTS, {card2.xPosition + card1.spacing, card1.yPosition});
    DisplayCard card4(KING, HEARTS, {card3.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card5(QUEEN, HEARTS, {card4.xPosition + card1.spacing,card1.yPosition});
    DisplayStats F("Flush 1/", PokerScore::FCOUNTER, {card1.xPosition, card1.yPosition - 70});

    window.draw(card1);
    window.draw(card2);
    window.draw(card3);
    window.draw(card4);
    window.draw(card5);
    window.draw(F);
}

void WinningCards::printS(sf::RenderWindow & window)
{

    DisplayCard card1(ACE, HEARTS, {1000,100});
    DisplayCard card2(TWO, HEARTS, {card1.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card3(THREE, CLUBS, {card2.xPosition + card1.spacing, card1.yPosition});
    DisplayCard card4(FOUR, HEARTS, {card3.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card5(FIVE, SPADES, {card4.xPosition + card1.spacing,card1.yPosition});
    DisplayStats F("Straight 1/", PokerScore::SCOUNTER, {card1.xPosition, card1.yPosition - 70});


    window.draw(card1);
    window.draw(card2);
    window.draw(card3);
    window.draw(card4);
    window.draw(card5);
    window.draw(F);
}

void WinningCards::printT(sf::RenderWindow & window)
{

    DisplayCard card1(ACE, HEARTS, {1000,400});
    DisplayCard card2(TWO, HEARTS, {card1.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card3(THREE, CLUBS, {card2.xPosition + card1.spacing, card1.yPosition});
    DisplayCard card4(THREE, HEARTS, {card3.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card5(THREE, SPADES, {card4.xPosition + card1.spacing,card1.yPosition});
    DisplayStats T("Three of a kind 1/", PokerScore::TCOUNTER, {card1.xPosition, card1.yPosition - 70});


    window.draw(card1);
    window.draw(card2);
    window.draw(card3);
    window.draw(card4);
    window.draw(card5);
    window.draw(T);
}

void WinningCards::printTP(sf::RenderWindow & window)
{

    DisplayCard card1(SEVEN, HEARTS, {1000,700});
    DisplayCard card2(NINE, SPADES, {card1.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card3(NINE, HEARTS, {card2.xPosition + card1.spacing, card1.yPosition});
    DisplayCard card4(JACK, CLUBS, {card3.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card5(JACK, SPADES, {card4.xPosition + card1.spacing,card1.yPosition});
    DisplayStats TP("Two pair 1/", PokerScore::TPCOUNTER, {card1.xPosition, card1.yPosition - 70});


    window.draw(card1);
    window.draw(card2);
    window.draw(card3);
    window.draw(card4);
    window.draw(card5);
    window.draw(TP);

}

void WinningCards::printOP(sf::RenderWindow & window)
{

    DisplayCard card1(FOUR, HEARTS, {1000,1000});
    DisplayCard card2(SEVEN, SPADES, {card1.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card3(NINE, HEARTS, {card2.xPosition + card1.spacing, card1.yPosition});
    DisplayCard card4(JACK, CLUBS, {card3.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card5(JACK, SPADES, {card4.xPosition + card1.spacing,card1.yPosition});
    DisplayStats OP("One pair 1/", PokerScore::OPCOUNTER, {card1.xPosition, card1.yPosition - 70});


    window.draw(card1);
    window.draw(card2);
    window.draw(card3);
    window.draw(card4);
    window.draw(card5);
    window.draw(OP);
}

void WinningCards::printHC(sf::RenderWindow & window)
{

    DisplayCard card1(THREE, HEARTS, {1000,1300});
    DisplayCard card2(JACK, SPADES, {card1.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card3(EIGHT, HEARTS, {card2.xPosition + card1.spacing, card1.yPosition});
    DisplayCard card4(FOUR, CLUBS, {card3.xPosition + card1.spacing,card1.yPosition});
    DisplayCard card5(TWO, SPADES, {card4.xPosition + card1.spacing,card1.yPosition});
    DisplayStats HC("High card 1/", PokerScore::HCCOUNTER, {card1.xPosition, card1.yPosition - 70});


    window.draw(card1);
    window.draw(card2);
    window.draw(card3);
    window.draw(card4);
    window.draw(card5);
    window.draw(HC);
}



