#pragma once
#ifndef EXIT_BUTTON_H
#define EXIT_BUTTON_H

#include"Button.h"
#include"GameManager.h"

namespace game {
    namespace gui {
        class ExitButton : public Button {
        public:
            ExitButton(GameManager*,Ogre::SceneManager*, Vector2, Vector2, string, bool);
            void onClick();
        private:
            GameManager *gameManager;
        };
    }
}

#endif
