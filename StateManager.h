#pragma once
#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include"AbstractAppState.h"
#include<vector>

namespace game {
    namespace core {
        class GameManager;
        class StateManager{
        public:
            StateManager(GameManager*);
            ~StateManager(){}
            void update();
            void attachState(AbstractAppState*);
            void dettachState(AbstractAppState*);
            void dettachState(StateType);
            AbstractAppState* getState(StateType);
            AbstractAppState* getState(int);
            int getNumberOfStates();
        private:
            GameManager *gameManager;
            std::vector<AbstractAppState*> states;
        };
    }
}

#endif /* STATEMANAGER_H */

