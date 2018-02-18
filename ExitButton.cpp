#include"ExitButton.h"

using namespace Ogre;
using namespace game;
using namespace gui;

ExitButton::ExitButton(GameManager *gM,SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr, pos, size, name, separate) {
    gameManager=gM;
}

void ExitButton::onClick() {
    gameManager->setIsRunning(false);
}
