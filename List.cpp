//
// Created by Khanh Nguyen on 12/8/22.
//
#include "List.h"

List::List()
{

}

List::List(std::string listName)
{
    list.push_back(ListItem(listName, {100,100}, {200,200}));
    list.push_back(ListItem("testing123", {100,100}, {200,200}));

    std::cout << list[0].buttonName;
    std::cout << list[1].buttonName;


//    for(int i = 1; i < list.size(); i++)
//    {
//        Position::bottom(list[i],list[i+1]);
//    }
}

void List::addItem(std::string listName)
{
    list.emplace_back(ListItem(listName, {0,0}, {0,0}));
}

void List::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    //target.draw(ListItem("testing box name", {500,100}, {0,100}));

    for(const ListItem& l : list)
    {
        target.draw(l);
    }
}


