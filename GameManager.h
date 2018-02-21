#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include <OGRE/Ogre.h>
#include <SDL/SDL.h>
#include <OGRE/Overlay/OgreOverlaySystem.h>
#include "StateManager.h"
#include "InputManager.h"
#include "GuiRect.h"
#include "GuiText.h"

using namespace Ogre;
using namespace game::gui;

namespace game {
    namespace core {
        class InputManager;
        class GameManager {
        public:
            GameManager();
            ~GameManager(){}
            void foo();
            void update();
            bool isRunning();
            void setIsRunning(bool);
            void addGuiRect(GuiRect*);
            void removeGuiRect(GuiRect*);
            void removeAllGuiRects();
            void addGuiText(GuiText*);
            void removeGuiText(GuiText*);
            void removeAllGuiTexts();
            SceneManager* getSceneManager();
            InputManager* getInputManager();
            StateManager* getStateManager();
            RenderWindow* getWindow();
            SDL_Surface getSurface();
            Root* getRoot();
        private:
            bool running=true;
            Ogre::Root *root;
            SDL_Surface *screen;
            RenderWindow *window;
            SceneManager *smgr;
            StateManager *stateManager;
            InputManager *inputManager=nullptr;
            OverlaySystem *overlaySystem;
            Viewport *viewport;
            SceneNode *camNode;
            std::vector<GuiRect*> rectangles;
            std::vector<GuiText*> texts;
        };
    }
}

#endif

