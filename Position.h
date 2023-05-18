//
// Created by Khanh Nguyen on 12/8/22.
//

#ifndef SFML_TEMPLATE_POSITION_H
#define SFML_TEMPLATE_POSITION_H
#include <SFML/Graphics.hpp>

class Position
{
public:
    template <class T>
    static void top(T& obj1, T& obj2);

    template <class T>
    static void bottom(T& obj1, T& obj2);

    template <class T>
    static void left(T& obj1, T& obj2);

    template <class T>
    static void right(T& obj1, T& obj2);

    template <class T>
    static void center(T& obj1, T& obj2);

    template <class T>
    static void centerBottom(T& obj1, T& obj2);

};

#include "Position.cpp"
#endif //SFML_TEMPLATE_POSITION_H
