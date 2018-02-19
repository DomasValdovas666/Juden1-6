#include"GuiAppState.h"
#include<iostream>

using namespace game;
using namespace core;

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
}

void GuiAppState::onDettachment() {
    AbstractAppState::onDettachment();
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
        if(name==buttons[i]->getName()){
            found=true;
            delete buttons[i];
            buttons.erase(buttons.begin()+i);
        }
}

void GuiAppState::removeAllButtons() {
    for (gui::Button *b : buttons)
        removeButton(b);
}

void GuiAppState::addListbox(Listbox *l) {
    listboxes.push_back(l);
}

void GuiAppState::removeListbox(Listbox *l) {
    bool found = false;
    for (int i = 0; i < listboxes.size()&&!found; i++)
        if (l == listboxes[i]) {
            found = true;
            l->remove();
            listboxes.erase(listboxes.begin() + i);
        }
}

void GuiAppState::removeAllListboxes() {
    for (Listbox *l : listboxes)
        removeListbox(l);
}

void GuiAppState::addCheckbox(Checkbox *c) {
    checkboxes.push_back(c);
}

void GuiAppState::removeCheckbox(Checkbox *c) {
    bool found = false;
    for (int i = 0; i < checkboxes.size()&&!found; i++)
        if (c == checkboxes[i]) {
            found = true;
            c->remove();
            checkboxes.erase(checkboxes.begin() + i);
        }
}

void GuiAppState::removeAllCheckboxes() {
    for (Checkbox *c : checkboxes)
        removeCheckbox(c);
}

void GuiAppState::addSlider(gui::Slider *s) {
    sliders.push_back(s);
}

void GuiAppState::removeSlider(gui::Slider *s) {
    bool found = false;
    for (int i = 0; i < sliders.size()&&!found; i++)
        if (s == sliders[i]) {
            found = true;
            s->remove();
            sliders.erase(sliders.begin() + i);
        }
}

void GuiAppState::removeAllSliders() {
    for (gui::Slider *s : sliders)
        removeSlider(s);
}

void GuiAppState::addTextbox(Textbox *t) {
    textboxes.push_back(t);
}

void GuiAppState::removeTextbox(Textbox *t) {
    bool found = false;
    for (int i = 0; i < textboxes.size()&&!found; i++)
        if (t == textboxes[i]) {
            found = true;
            t->remove();
            textboxes.erase(textboxes.begin() + i);
        }
}

void GuiAppState::removeAllTextboxes() {
    for (Textbox *t : textboxes)
        removeTextbox(t);
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
