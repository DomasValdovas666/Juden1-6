#include "StateManager.h"

using namespace game;
using namespace core;

StateManager::StateManager(GameManager *gM) {
    gameManager = gM;
}

void StateManager::update() {
    for (AbstractAppState *a : states)
        a->update();
}

void StateManager::attachState(AbstractAppState *a) {
    a->onAttachment();
    states.push_back(a);
}

void StateManager::dettachState(AbstractAppState *a) {
    for (int i = 0; i < states.size(); i++)
        if (states[i] == a)
            states.erase(states.begin() + i);
}

void StateManager::dettachState(StateType t) {
    for (int i = 0; i < states.size(); i++)
        if (t == states[i]->getType())
            states.erase(states.begin() + i);
}

AbstractAppState* StateManager::getState(StateType t) {
    AbstractAppState *a = nullptr;
    for (int i = 0; i < states.size(); i++)
        if (t == states[i]->getType())
            a = states[i];
    return a;
}

AbstractAppState* StateManager::getState(int i){
    return states[i];
}

int StateManager::getNumberOfStates(){
    return states.size();
}
