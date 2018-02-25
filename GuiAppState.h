#pragma once
#ifndef GUIAPPSTATE_H
#define GUIAPPSTATE_H

#include"GameManager.h"
#include"Button.h"
#include"Listbox.h"
#include"Checkbox.h"
#include"Slider.h"
#include"Textbox.h"
#include<vector>
#include<string>

using namespace std;
using namespace game::gui;

namespace game{
    namespace core{
        class GuiAppState : public AbstractAppState{
        public:
            GuiAppState(GameManager*);
            ~GuiAppState(){}
            void update();
            void onAttachment();
            void onDettachment();
            void addButton(gui::Button*);
            void removeButton(gui::Button*);
            void removeButton(string);
            void removeAllButtons();
            void addListbox(gui::Listbox*);
            void removeListbox(Listbox*);
            void removeAllListboxes();
            void addCheckbox(gui::Checkbox*);
            void removeCheckbox(Checkbox*);
            void removeAllCheckboxes();
            void addSlider(gui::Slider*);
            void removeSlider(gui::Slider*);
            void removeAllSliders();
            void addTextbox(gui::Textbox*);
            void removeTextbox(Textbox*);
            void removeAllTextboxes();
            void removeAllGUIElements();
            void onAction(string,bool);
            void onAnalog(string,float);
        private:
            std::vector<gui::Button*> buttons;
            std::vector<gui::Listbox*> listboxes;
            std::vector<gui::Checkbox*> checkboxes;
            std::vector<gui::Slider*> sliders;
            std::vector<gui::Textbox*> textboxes;
            const int keyboardTriggers[3][2]{
                {0x02,0x0B},
                {0x10,0x1B},
                {0x1E,0x35}
            };
            void addKeyboardKeys();
            void checkKeyboardKeys(Textbox*,string);
        };
    }
}

#endif /* GUIAPPSTATE_H */

