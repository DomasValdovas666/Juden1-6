#include"Slider.h"
#include<algorithm>
#include"DefConfigs.h"
#include"Util.h"
#include<sstream>

using namespace Ogre;
using namespace game;
using namespace gui;

Slider::MovableSliderButton::MovableSliderButton(Slider *slider, OIS::Mouse *mouse, SceneManager *smgr,Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr,pos, size, name, separate) {
    this->slider = slider;
    this->mouse=mouse;
}

void Slider::MovableSliderButton::onClick() {
    clicked = !clicked;
}

void Slider::MovableSliderButton::update() {
    int posX = mouse->getMouseState().X.abs, posY = mouse->getMouseState().Y.abs;
    if (clicked && posY > slider->getPos().y && posY < slider->getPos().y + slider->getSize().y) {
        if (posX < slider->getPos().x)
            posX = slider->getPos().x;
        else if (posX > slider->getPos().x + slider->getSize().x)
            posX = slider->getPos().x + slider->getSize().x;
        slider->setValue((((double) posX - slider->getPos().x) / slider->getSize().x) * slider->getMaxValue());
    }
}

Slider::StaticSliderButton::StaticSliderButton(Slider *slider,OIS::Mouse *mouse, SceneManager *smgr,Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr,pos, size, name, separate) {
    this->slider = slider;
}

void Slider::StaticSliderButton::onClick() {
    s16 buttonClickPoint = -slider->getPos().x + mouse->getMouseState().X.abs;
    slider->setValue(((double) buttonClickPoint / slider->getSize().x) * slider->getMaxValue());
}

Slider::Slider(OIS::Mouse *mouse,SceneManager *smgr,Vector2 pos, Vector2 size, double minValue, double maxValue) {
    this->pos = pos;
    this->size = size;
    this->minValue = minValue;
    this->maxValue = maxValue;
    staticSliderButton = new StaticSliderButton(this, mouse,smgr,pos, size, "StaticSliderButton", false);
    movableSliderButton = new MovableSliderButton(this, mouse,smgr,Vector2(pos.x + staticSliderButton->getSize().x / 1, pos.y - 15), Vector2(10, 40), "MovableSliderButton", false);
    value = (maxValue - minValue) / 2;
    for(int i=0;i<2;i++){

    }
}

Slider::~Slider() {
}

void Slider::update() {
    if (value < minValue)
        value = minValue;
    else if (value > maxValue)
        value = maxValue;
    movableSliderButton->update();
    //driver->draw2DRectangle(*staticSliderButton->getColor(), rect<s32>(pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y), nullptr);
    Vector2 p = movableSliderButton->getPos(), s = movableSliderButton->getSize();
    p.x = pos.x + (double) size.x / maxValue * value;
    //driver->draw2DRectangle(SColor(255, 200, 200, 200), rect<s32>(p.X, p.Y, p.X + s.X, p.Y + s.Y), nullptr);
    movableSliderButton->setPos(p);
}

void Slider::addTextbox(Textbox *t) {
    textbox = t;
}

void Slider::remove(){
    delete this;
}

Textbox* Slider::getTextbox() {
    return textbox;
}

double Slider::getMinValue() {
    return minValue;
}

double Slider::getValue() {
    return value;
}

double Slider::getMaxValue() {
    return maxValue;
}

double Slider::getIncrement() {
    return increment;
}

void Slider::setIncrement(double increment) {
    this->increment = increment;
}

void Slider::setValue(double value) {
    this->value = value;
}

Slider::MovableSliderButton* Slider::getMovableSliderButton() {
    return movableSliderButton;
}

Slider::StaticSliderButton* Slider::getStaticSliderButton() {
    return staticSliderButton;
}

Vector2 Slider::getPos() {
    return pos;
}

Vector2 Slider::getSize() {
    return size;
}
