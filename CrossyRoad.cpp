//
// Created by Khanh Nguyen on 12/13/22.
//

#include "CrossyRoad.h"


CrossyRoad::CrossyRoad()
{
    srand(time(0));
    int randTime = rand() % 5;
    //ListItem item = ListItem("menu", {300,100}, {300, 200});

    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Crossy Road");

    StartingScreen mainMenu;
    WinLose hearts;

    Player player1;
    ListItem hi = ListItem("hello", {100,100}, {100,100});
    ListItem bye = ListItem("bye", {100,100}, {100,100});
    ListItem topBar("CROSS THE ROAD" , {1920,100}, {0,0});
    Position::bottom(hi,bye);

    Map pond = Map();

    CarRow carRowTest1(0.2, {800,100}, LOG);
    CarRow carRowTest2(0.15, {0,1080/2}, LILYPAD);
    CarRow carRowTest3(0.05, {0,1080/2}, LOG);
    CarRow carRowTest4(0.1, {0,1080/2}, LOG);

    CarRow carRowTest5(0.02, {800,1080/2 + 100}, CAR);
    CarRow carRowTest6(0.15, {0,1080/2}, CAR);
    CarRow carRowTest7(0.07, {0,1080/2}, CAR);
    CarRow carRowTest8(0.10, {0,1080/2}, CAR);

    Position::bottom(carRowTest1, carRowTest2); //create a special position function for bottoming each car[i] in row
    Position::bottom(carRowTest2, carRowTest3);
    Position::bottom(carRowTest3, carRowTest4);

    Position::bottom(carRowTest5, carRowTest6);
    Position::bottom(carRowTest6, carRowTest7);
    Position::bottom(carRowTest7, carRowTest8);

    sf::Clock clock;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        window.draw(pond);
        carRowTest1.move();
        carRowTest1.collide(player1);
        window.draw(carRowTest1);

        carRowTest2.move();
        carRowTest2.collide(player1);
        window.draw(carRowTest2);

        carRowTest3.move();
        carRowTest3.collide(player1);
        window.draw(carRowTest3);

        carRowTest4.move();
        carRowTest4.collide(player1);
        window.draw(carRowTest4);

        carRowTest5.move();
        carRowTest5.collide(player1);
        window.draw(carRowTest5);

        carRowTest6.move();
        carRowTest6.collide(player1);
        window.draw(carRowTest6);

        carRowTest7.move();
        carRowTest7.collide(player1);
        window.draw(carRowTest7);

        carRowTest8.move();
        carRowTest8.collide(player1);
        window.draw(carRowTest8);

        window.draw(player1);
        player1.reachTop();
        player1.move(100,100);

        hearts.eventHandler(player1, window, event);
        window.draw(hearts);

        //mainMenu.eventHandler(window, event);
        //window.draw(mainMenu);

        player1.animate();
        window.display();
    }

}
