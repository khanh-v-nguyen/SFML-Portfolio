//
// Created by Khanh Nguyen on 12/8/22.
//

#ifndef SFML_TEMPLATE_LIST_H
#define SFML_TEMPLATE_LIST_H
#include "ListItem.h"
#include "Position.h"
#include <vector>
class List : public sf::Drawable
{
public:
    List();
    List(std::string listName);
    std::vector<ListItem> list;
    void addItem(std::string listName);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif //SFML_TEMPLATE_LIST_H
