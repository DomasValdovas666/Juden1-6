#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include<OIS.h>
#include<OGRE/Ogre.h>
#include"GameManager.h"
#include"GuiRect.h"

#define USE_KEYBOARD 1
#define USE_MOUSE 1

using namespace Ogre;

namespace game {
    namespace core {
        class GameManager;
        class InputManager{
        public:
            InputManager(GameManager*,RenderWindow*);
            ~InputManager(){}
            void update();
            OIS::Keyboard* getKeyboard();
            OIS::Mouse* getMouse();
        private:
            StateManager *stateManager;
            OIS::Keyboard *keyboard=nullptr;
            OIS::Mouse *mouse=nullptr;
            gui::GuiRect *cursor;
            void updateKeyboard(AbstractAppState*,Key*);
            void updateMouse(AbstractAppState*,Key*);
        };
    }
}

#endif /* INPUTMANAGER_H */

