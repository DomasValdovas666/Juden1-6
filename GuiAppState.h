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
            void addListbox(Listbox*);
            void removeListbox(Listbox*);
            void removeAllListboxes();
            void addCheckbox(Checkbox*);
            void removeCheckbox(Checkbox*);
            void removeAllCheckboxes();
            void addSlider(gui::Slider*);
            void removeSlider(gui::Slider*);
            void removeAllSliders();
            void addTextbox(Textbox*);
            void removeTextbox(Textbox*);
            void removeAllTextboxes();
            void removeAllGUIElements();
            void onAction(string,bool);
            void onAnalog(string,float);
        private:
            std::vector<gui::Button*> buttons;
            std::vector<Listbox*> listboxes;
            std::vector<Checkbox*> checkboxes;
            std::vector<gui::Slider*> sliders;
            std::vector<Textbox*> textboxes;
        };
    }
}

#endif /* GUIAPPSTATE_H */

