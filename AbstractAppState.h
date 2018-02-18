#pragma once
#ifndef ABSTRACTAPPSTATE_H
#define ABSTRACTAPPSTATE_H

#include"Key.h"
#include<vector>
#include<string>

using namespace std;

namespace game{
    namespace core{
        class GameManager;
        enum class StateType{GUI_STATE,IN_GAME_STATE,ACTIVE_STATE};
        class AbstractAppState{
        public:
            AbstractAppState(GameManager*);
            ~AbstractAppState(){}
            virtual void update();
            virtual void onAttachment();
            virtual void onDettachment();
            StateType getType();
            bool isAttached();
            int getNumberOfKeys();
            Key* getKey(int);
            GameManager* getGameManager();
            virtual void onAction(string,bool);
            virtual void onAnalog(string,float);
        protected:
            GameManager *gameManager;
            bool attached=false;
            std::vector<Key*> keys;
            StateType type;
        };
    }
}

#endif /* ABSTRACTAPPSTATE_H */

