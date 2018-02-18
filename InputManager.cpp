#include"InputManager.h"
#include"DefConfigs.h"

using namespace OIS;
using namespace game;
using namespace core;

class GameManager;

core::InputManager::InputManager(GameManager *gM, RenderWindow *window) {
    this->stateManager = gM->getStateManager();
    size_t windowHnd = 0;
    window->getCustomAttribute("WINDOW", &windowHnd);
    std::string s = "";
    std::ostringstream ss;
    ss << windowHnd;
    s = ss.str();
    ParamList pl;
    pl.insert(std::make_pair(std::string("WINDOW"), s));
    OIS::InputManager *ip = OIS::InputManager::createInputSystem(pl);
    if(USE_KEYBOARD == 1)
        keyboard = static_cast<Keyboard*> (ip->createInputObject(OISKeyboard, true));
    if(USE_MOUSE == 1)
        mouse = static_cast<Mouse*> (ip->createInputObject(OISMouse, true));
    cursor = new gui::GuiRect(gM->getSceneManager(),Vector2(0,0),Vector2(10,10),PATH+"Textures/cursor.png");
}

void core::InputManager::update() {
    if(keyboard)
        keyboard->capture();
    if(mouse){
        Vector2 pos=Vector2(mouse->getMouseState().X.abs,mouse->getMouseState().Y.abs);
        cursor->setPos(pos);
        mouse->capture();
    }
    for (int i = 0; i < stateManager->getNumberOfStates(); i++) {
        AbstractAppState *a = stateManager->getState(i);
        for (int i2 = 0; i2 < stateManager->getState(i)->getNumberOfKeys(); i2++) {
            Key *k = stateManager->getState(i)->getKey(i2);
            if(k->isKey()&&keyboard)
                updateKeyboard(a,k);
            else if(!k->isKey()&&mouse)
                updateMouse(a,k);
        }
    }
}

void core::InputManager::updateKeyboard(AbstractAppState *a,Key *k) {
    if (k->isAction()&&keyboard->isKeyDown((KeyCode) k->getTrigger())) {
        k->setIsPressed(!k->isPressed());
        if (!k->isUsedBefore())
            a->onAction(k->getBind(), k->isPressed());
        k->setUsedBefore(k->isPressed());
    } else {
        a->onAnalog(k->getBind(), 0);
    }
}

void core::InputManager::updateMouse(AbstractAppState *a,Key *k) {
    if (k->isAction()&&mouse->getMouseState().buttonDown((MouseButtonID)k->getTrigger())) {
        k->setIsPressed(!k->isPressed());
        if (!k->isUsedBefore())
            a->onAction(k->getBind(), k->isPressed());
        k->setUsedBefore(k->isPressed());
    } else {
        a->onAnalog(k->getBind(), 0);
    }
}

Keyboard* core::InputManager::getKeyboard() {
    return keyboard;
}

Mouse* core::InputManager::getMouse() {
    return mouse;
}
