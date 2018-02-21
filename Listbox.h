#pragma once
#ifndef LISTBOX_H
#define LISTBOX_H

#include"Button.h"
#include<OIS.h>

using namespace OIS;
using namespace Ogre;

namespace game {
    namespace gui {
        class Listbox {
        public:
            Listbox(Mouse*, SceneManager*,Vector2, Vector2, std::vector<string>, int);
            ~Listbox();
            void update();
            void openUp();
            void close();
            void scrollUp();
            void scrollDown();
            void addLine(string);
            void changeLine(int, string);
            void remove();
            bool isOpen();
            void appendLines(std::vector<string>&);
            std::vector<string> getContents();
            int getSelectedOption();
        private:
            class ListboxButton : public Button {
            public:
                ListboxButton(Listbox*, SceneManager*,Vector2, Vector2, string, bool);
                void onClick();
            private:
                Listbox *listbox = nullptr;
            };
            class ScrollingButton : public Button {
            public:

                ScrollingButton(SceneManager*,Vector2, Vector2, string, bool);
                void onClick();
            private:
            };
            int maxDisplay, scrollOffset = 0, selectedOption = 0;
            bool open = false;
            std::vector<GuiText*> lines;
            Vector2 pos, size;
            ListboxButton *listboxButton;
            ScrollingButton *scrollingButton;
            GuiRect *selRect;
            Mouse *mouse;
        public:
            ListboxButton* getListboxButton();
            ScrollingButton* getScrollingButton();
        };
    }
}

#endif
