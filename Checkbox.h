#pragma once
#ifndef CHECKBOX_H
#define CHECKBOX_H

#include"Button.h"

using namespace Ogre;

namespace game {
    namespace gui {
        class Checkbox {
        public:
            Checkbox(SceneManager*,Vector2);
            ~Checkbox(){}
            void update();
            void check();
            void remove();
            bool isChecked();
        private:
            class CheckboxButton : public Button {
            public:
                CheckboxButton(Checkbox*,SceneManager*, Vector2, Vector2, string, bool);
                void onClick();
            private:
                Checkbox *checkbox = nullptr;
            };
            const int length = 15;
            bool checked = false;
            Vector2 pos;
            GuiText *xMark=nullptr;
            CheckboxButton *checkboxButton;
        public:
            CheckboxButton* getCheckboxButton();
        };
    }
}

#endif
