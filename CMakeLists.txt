cmake_minimum_required(VERSION 3.17)
project(SFML_Template)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML_Template main.cpp Player.h Player.cpp Obstacles.cpp Obstacles.h StartingScreen.h StartingScreen.cpp ListItem.h ListItem.cpp List.h List.cpp Position.h Position.cpp CarRow.h CarRow.cpp ObstacleType.h Map.h Map.cpp MouseEvents.h MouseEvents.cpp CrossyRoad.h CrossyRoad.cpp bootlegMain.cpp PortfolioScreen.h PortfolioScreen.cpp GameEnum.h GreenCircleFiles/GreenCircle.h GreenCircleFiles/GreenCircle.cpp Portfolio.cpp Portfolio.h TopHatGuyFiles/TophatGuyRun.h TopHatGuyFiles/TophatGuyRun.cpp TopHatGuyFiles/TophatGuy.cpp TopHatGuyFiles/TophatGuy.h PongFiles/PongBall.h PongFiles/PongBall.cpp PongFiles/PongBallRun.h PongFiles/PongBallRun.cpp PongFiles/PongPaddle.h PongFiles/PongPaddle.cpp WinLose.h WinLose.cpp States.h States.cpp statesEnum.h PokerAnalysisFiles/PokerAnalysisRun.h PokerAnalysisFiles/PokerAnalysisRun.cpp PokerAnalysisFiles/Card.cpp PokerAnalysisFiles/Card.h PokerAnalysisFiles/rankEnum.h PokerAnalysisFiles/suitEnum.h PokerAnalysisFiles/Deck.h PokerAnalysisFiles/Deck.cpp PokerAnalysisFiles/CardHand.h PokerAnalysisFiles/CardHand.cpp PokerAnalysisFiles/CardHandScorer.cpp PokerAnalysisFiles/CardHandScorer.h PokerAnalysisFiles/PokerScore.h PokerAnalysisFiles/PokerScore.cpp PokerAnalysisFiles/DrawCard.cpp PokerAnalysisFiles/DrawCard.h PokerAnalysisFiles/Position.h PokerAnalysisFiles/Position.cpp PokerAnalysisFiles/WinningCards.h PokerAnalysisFiles/WinningCards.cpp PokerAnalysisFiles/DisplayCard.h PokerAnalysisFiles/DisplayCard.cpp PokerAnalysisFiles/DisplayStats.h PokerAnalysisFiles/DisplayStats.cpp)

target_link_libraries(SFML_Template sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)