//
// Created by Khanh Nguyen on 12/13/22.
//
//
//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include "Player.h"
//#include "Obstacles.h"
//#include "ListItem.h"
//#include "List.h"
//#include "CarRow.h"
//#include "Map.h"
//#include <ctime>
//#include "StartingScreen.h"
//
//int main() {
//    srand(time(0));
//    int randTime = rand() % 5;
//    //ListItem item = ListItem("menu", {300,100}, {300, 200});
//
//    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Test");
//
//    StartingScreen mainMenu;
//
//    Player player1;
//    Player player2;
//    ListItem hi = ListItem("hello", {100,100}, {100,100});
//    ListItem bye = ListItem("bye", {100,100}, {100,100});
//    ListItem topBar("CROSS THE ROAD" , {1920,100}, {0,0});
//    Position::bottom(hi,bye);
//
//    Map pond = Map();
//
//    CarRow carRowTest1(0.2, {0,1080/2 - 300}, LOG);
//    CarRow carRowTest2(0.15, {0,1080/2}, LOG);
//    CarRow carRowTest3(0.05, {0,1080/2}, LOG);
//    CarRow carRowTest4(0.1, {0,1080/2}, CAR);
//
//    Position::bottom(carRowTest1, carRowTest2); //create a special position function for bottoming each car[i] in row
//    Position::bottom(carRowTest2, carRowTest3);
//    Position::bottom(carRowTest3, carRowTest4);
//
//
//    //List a = List("load");
//
//    //Position::bottom(o1,o2);
//    sf::Clock clock;
//    std::vector<Obstacles> allObstacles;
//
////    std::vector<Obstacles> carVec1(5, Obstacles());
////    for(int i = 0; i < carVec1.size(); i++) //make a seperate class for car vectors
////    {
////        if(i==0)
////        {
////            i++;
////        }
////        carVec1[i].setPosition(carVec1[i-1].getObstaclePosition().x - 500,carVec1[i-1].getObstaclePosition().y);
////    }
//
//    //allObstacles.push_back(Obstacles());
////    for(int i = 0; i < 5; i++)
////    {
////        allObstacles.push_back(Obstacles());
////        allObstacles[i].setPosition(i * 100, 300);
////    }
//    auto iter = allObstacles.begin();
//    //create two player objects (move mousepressed)
//    //create a asteroid class (move, non consistent)
//
//    while(window.isOpen())
//    {
//        sf::Event event;
//        while(window.pollEvent(event)){
//            if (event.type == sf::Event::Closed){
//                window.close();
//            }
//            //h.fly(window.getSize());
//        }
//
//        window.clear(sf::Color::Black);
//
//        window.draw(pond);
//        carRowTest1.move();
//        carRowTest1.collide(player1);
//        window.draw(carRowTest1);
//
//        carRowTest2.move();
//        carRowTest2.collide(player1);
//        window.draw(carRowTest2);
//
//        carRowTest3.move();
//        carRowTest3.collide(player1);
//        window.draw(carRowTest3);
//
//        carRowTest4.move();
//        carRowTest4.collide(player1);
//        window.draw(carRowTest4);
//
//        //window.draw(topBar);
//
//        window.draw(player1);
//        player1.reachTop();
//        player1.move(100,100);
//
//        mainMenu.eventHandler(window, event);
//        window.draw(mainMenu);
//
////        for(int i = 1; i < carVec1.size(); i++)
////        {
////            carVec1[i].fly();
////            carVec1[i].collide(player1);
////            window.draw(carVec1[i]);
////        }
//
////        if(clock.getElapsedTime().asSeconds() > 2)
////        {
////            allObstacles.push_back(Obstacles());
////            allObstacles.back().setPosition(0, 300); //change in constructor to make car move from left of screen
////            clock.restart();
////        }
////
////        for(Obstacles& o : allObstacles)
////        {
////            //o.move({0.3,0});
////            o.fly();
////            o.collide(player1);
////            window.draw(o);
////        }
//        player1.animate();
//        //window.draw(a);
//        window.display();
//    }
//    return 0;
//}
