#include"Key.h"

using namespace game;
using namespace core;

Key::Key(string bind, int trigger, bool key, bool action) {
    this->bind = bind;
    this->trigger = trigger;
    this->key = key;
    this->action = action;
}

string Key::getBind() {
    return bind;
}

int Key::getTrigger() {
    return trigger;
}

bool Key::isKey() {
    return key;
}

bool Key::isAction() {
    return action;
}

bool Key::isPressed() {
    return pressed;
}

bool Key::isUsedBefore() {
    return usedBefore;
}

void Key::setUsedBefore(bool b) {
    usedBefore = b;
}

void Key::setIsPressed(bool p) {
    pressed=p;
}
