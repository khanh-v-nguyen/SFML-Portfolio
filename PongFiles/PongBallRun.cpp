//
// Created by Khanh Nguyen on 12/14/22.
//
#include "PongBallRun.h"

PongBallRun::PongBallRun()
{
    sf::RenderWindow window(sf::VideoMode(720, 420, 32), "Pong");
    PongBall circle;
    PongPaddle paddle;
    PongBall circ2;
    PongPaddle paddle2;

    circ2.setRadius(20);
    circ2.setPosition({100,20});
    circ2.setFillColor(sf::Color::Yellow);
    circ2.setVelocity({0.10, 0.15});

    paddle.setFillColor(sf::Color::Red);
    paddle.setSize({20,100});
    paddle.setPosition({50,50});

    paddle2.setFillColor(sf::Color::Blue);
    paddle2.setSize({20,100});
    paddle2.setPosition({670,50});

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                circle.bounce(window.getSize());
            }
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//            {
//                paddle2.jump(window.getSize());
//                paddle.jump(window.getSize());
//            }
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//            {
//                paddle.jump(window.getSize());
//                paddle2.jump(window.getSize());
//            }
        }

        window.clear(sf::Color::Black);
        window.draw(paddle);
        window.draw(paddle2);
        window.draw(circ2);

        circ2.bounce(window.getSize());

        paddle.jump(window.getSize());
        paddle2.jump2(window.getSize());

        paddle.collide(circ2, window.getSize());
        paddle2.collide(circ2, window.getSize());
        window.display();
    }

}
