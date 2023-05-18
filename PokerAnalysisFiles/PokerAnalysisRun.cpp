
#include "PokerAnalysisRun.h"

PokerAnalysisRun::PokerAnalysisRun()
{
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(1920, 1600, 32), "Test");
    while(PokerScore::RFCOUNTER != 1)
    {
        Deck deck;
        CardHand ch, ch2, ch3, ch4, ch5;

        for(int i = 0; i < 5; i++)
        {
            ch.addCard(deck.dealCard());
            ch2.addCard(deck.dealCard());
            ch3.addCard(deck.dealCard());
            ch4.addCard(deck.dealCard());
            ch5.addCard(deck.dealCard());
        }
        ch.sortRanks();
        ch.countPairs();
        ch.countSameRanks();
        PokerScore pokerScore = CardHandScorer::scorePokerHand(ch);
        //std::cout << ch;
        //std::cout << pokerScore;
    }

    CardHandScorer::outputScores();

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        WinningCards::printRY(window);
        WinningCards::printSF(window);
        WinningCards::printFOAK(window);
        WinningCards::printF(window);
        WinningCards::printFH(window);
        WinningCards::printS(window);
        WinningCards::printT(window);
        WinningCards::printTP(window);
        WinningCards::printOP(window);
        WinningCards::printHC(window);

        window.display();
    }
}


