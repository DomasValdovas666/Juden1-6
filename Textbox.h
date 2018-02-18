#pragma once
#ifndef TEXTBOX_H
#define TEXTBOX_H

#include"Button.h"

using namespace Ogre;

namespace game {
    namespace gui {
        class Textbox {
        public:
            Textbox(SceneManager*,Vector2, Vector2);
            ~Textbox(){}
            void update();
            void enable();
            void disable();
            void type(wchar_t);
            void moveCursor(bool);
            void deleteCharacter();
            string getEntry();
            void setEntry(string);
            bool isEnabled();
            bool isCapitalLeters();
            void setIsCapitalLeters(bool);
            void remove();
        private:
            class TextboxButton : public Button {
            public:
                TextboxButton(Textbox*, SceneManager*,Vector2, Vector2, string, bool);
                void onClick();
            private:
                Textbox *textbox;
            };
            const int cursorWidth=5;
            Vector2 pos, size;
            string entry = "";
            bool enabled, canShowCursor = false, capitalLeters = false;
            TextboxButton *textboxButton;
            GuiRect *cursorRect;
            float fontWidth=20;
            s64 lastBlinkTime, cursorPosOffset = 0;
            bool canChangeCursor();
        public:
            TextboxButton* getTextboxButton();
        };
    }
}

#endif
