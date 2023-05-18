//
// Created by Khanh Nguyen on 12/14/22.
//

#ifndef SFML_TEMPLATE_STATES_H
#define SFML_TEMPLATE_STATES_H

#include <map>
#include "statesEnum.h"
class States
{
private:
    std::map<statesEnum, bool> map;
    void load();
public:
    States();
    bool checkStates(statesEnum state) const; //check if enum in map?, const bc we just wanna check not change a value
    void enableStates(statesEnum state); // make state true inside of map
    void disableStates(statesEnum state);
    void setState(statesEnum state, bool value); //pass in state , pass in what i want it to be
    void toggleState(statesEnum state);//change state from true to false
};

#endif //SFML_TEMPLATE_STATES_H
