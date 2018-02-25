#include"GuiAppState.h"
#include<algorithm>
#include<ostream>

namespace game {
    namespace core {
        GuiAppState::GuiAppState(GameManager *gM) : AbstractAppState(gM) {
            type=StateType::GUI_STATE;
        }

        void GuiAppState::update() {
            for (gui::Button *b : buttons)
                b->update();
            for (Listbox *l : listboxes)
                l->update();
            for (Checkbox *c : checkboxes)
                c->update();
            for (gui::Slider *s : sliders)
                s->update();
            for (Textbox *t : textboxes)
                t->update();
        }

        void GuiAppState::onAttachment() {
            AbstractAppState::onAttachment();
            addKeyboardKeys();
        }

        void GuiAppState::onDettachment() {
            AbstractAppState::onDettachment();
        }

        void GuiAppState::addKeyboardKeys(){
            for(int i=0;i<sizeof(keyboardTriggers)/8;i++)
                for(int i2=keyboardTriggers[i][0];i2<=keyboardTriggers[i][1];i2++) {
                    std::stringstream ss;
                    ss>>i2;
                    keys.push_back(new Key(ss.str(),i2,1,1));
                }
        }

        void GuiAppState::addButton(gui::Button *b) {
            buttons.push_back(b);
        }

        void GuiAppState::removeButton(gui::Button *b) {
            bool found = false;
            for (int i = 0; i < buttons.size()&&!found; i++)
                if (b == buttons[i]) {
                    found = true;
                    b->remove();
                    buttons.erase(buttons.begin() + i);
                }
        }

        void GuiAppState::removeButton(string name){
            bool found=false;
            for(int i=0;i<buttons.size()&&!found;i++)
                if(name==buttons[i]->getName()&&buttons[i]->isSeparate()){
                    found=true;
                    buttons[i]->remove();
                    buttons.erase(buttons.begin()+i);
                }
        }

        void GuiAppState::removeAllButtons() {
            int separateButtons=0;
            for(int i=0;i<buttons.size();i++)
                if(buttons[i]->isSeparate())
                    separateButtons++;
            for(int i=0;separateButtons==0;i++) {
                if(buttons[i]->isSeparate()) {
                    buttons[i]->remove();
                    buttons.erase(buttons.begin()+i);
                    separateButtons--;
                }
            }
        }

        void GuiAppState::addListbox(gui::Listbox *l) {
            listboxes.push_back(l);
            buttons.push_back(l->getListboxButton());
            buttons.push_back(l->getScrollingButton());
        }

        void GuiAppState::removeListbox(gui::Listbox *l) {
            bool found = false;
            for (int i = 0; i < listboxes.size()&&!found; i++)
                if (l == listboxes[i]) {
                    found = true;
                    removeButton(l->getScrollingButton());
                    removeButton(l->getListboxButton());
                    listboxes.erase(listboxes.begin() + i);
                }
        }

        void GuiAppState::removeAllListboxes() {
            while (!listboxes.empty()) {
                gui::Listbox *l=listboxes[listboxes.size()-1];
                removeButton(l->getListboxButton());
                removeButton(l->getScrollingButton());
                l->remove();
                listboxes.pop_back();
            }
        }

        void GuiAppState::addCheckbox(Checkbox *c) {
            checkboxes.push_back(c);
            buttons.push_back(c->getCheckboxButton());
        }

        void GuiAppState::removeCheckbox(gui::Checkbox *c) {
            bool found = false;
            for (int i = 0; i < checkboxes.size()&&!found; i++)
                if (c == checkboxes[i]) {
                    found = true;
                    removeButton(c->getCheckboxButton());
                    c->remove();
                    checkboxes.erase(checkboxes.begin() + i);
                }
        }

        void GuiAppState::removeAllCheckboxes() {
            while(!checkboxes.empty()) {
                gui::Checkbox *c=checkboxes[checkboxes.size()-1];
                removeButton(c->getCheckboxButton());
                c->remove();
                checkboxes.pop_back();
            }
        }

        void GuiAppState::addSlider(gui::Slider *s) {
            sliders.push_back(s);
            buttons.push_back(s->getMovableSliderButton());
            buttons.push_back(s->getStaticSliderButton());
        }

        void GuiAppState::removeSlider(gui::Slider *s) {
            bool found = false;
            for (int i = 0; i < sliders.size()&&!found; i++)
                if (s == sliders[i]) {
                    found = true;
                    removeButton(s->getMovableSliderButton());
                    removeButton(s->getStaticSliderButton());
                    s->remove();
                    sliders.erase(sliders.begin() + i);
                }
        }

        void GuiAppState::removeAllSliders() {
            while(!sliders.empty()) {
                gui::Slider *s=sliders[sliders.size()-1];
                removeButton(s->getStaticSliderButton());
                removeButton(s->getMovableSliderButton());
                s->remove();
                sliders.pop_back();
            }
        }

        void GuiAppState::addTextbox(gui::Textbox *t) {
            textboxes.push_back(t);
            buttons.push_back(t->getTextboxButton());
        }

        void GuiAppState::removeTextbox(gui::Textbox *t) {
            bool found = false;
            for (int i = 0; i < textboxes.size()&&!found; i++)
                if (t == textboxes[i]) {
                    found = true;
                    removeButton(t->getTextboxButton());
                    t->remove();
                    textboxes.erase(textboxes.begin() + i);
                }
        }

        void GuiAppState::removeAllTextboxes() {
            while(!textboxes.empty()){
                gui::Textbox *t=textboxes[textboxes.size()-1];
                removeButton(t->getTextboxButton());
                t->remove();
                textboxes.pop_back();
            }
        }

        void GuiAppState::checkKeyboardKeys(gui::Textbox *t,string bind) {
            int sum=0;
            for(int i=0;i<sizeof(keyboardTriggers)/8;i++)
                sum+=(keyboardTriggers[i][1]-keyboardTriggers[i][0]);
            for(int i=keys.size()-1;i=keys.size()-sum;i--)
                if(keys[i]->getBind()==bind) {}
        }

        void GuiAppState::onAction(string bind, bool isPressed) {
            int posX=gameManager->getInputManager()->getMouse()->getMouseState().X.abs;
            int posY=gameManager->getInputManager()->getMouse()->getMouseState().Y.abs;
            if(bind=="leftClick"&&isPressed){
                for(int i=0;i<buttons.size();i++){
                    Ogre::Vector2 pos=buttons[i]->getPos();
                    Ogre::Vector2 size=buttons[i]->getSize();
                    if(posX>pos.x&&posX<pos.x+size.x&&posY>pos.y&&posY<pos.y+size.y)
                        buttons[i]->onClick();
                }
            }
        }

        void GuiAppState::onAnalog(string bind, float str) {
        }
    }
}
