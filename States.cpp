//
// Created by Khanh Nguyen on 12/14/22.
//

#include "States.h"

#include "States.h"

States::States()
{
    load();
}

void States::load() //add all states to map, default them to false
{
    for(int i = 0; i<LAST_STATE; i++)
    {
        map[static_cast<statesEnum>(i)] = false;
    }
}

bool States::checkStates(statesEnum state) const
{
    return map.at(state);
}

void States::enableStates(statesEnum state)
{
    setState(state, true);
}

void States::disableStates(statesEnum state)
{
    setState(state, false);
}

void States::setState(statesEnum state, bool value)
{
    map.at(state) = value;
}

void States::toggleState(statesEnum state)
{
    setState(state, !map.at(state));
}
