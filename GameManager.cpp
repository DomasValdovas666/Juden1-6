#include"GameManager.h"
#include"DefConfigs.h"

using namespace Ogre;
using namespace game;
using namespace core;
using namespace gui;

GameManager::GameManager() {
    root = new Root("plugins.cfg");
    root->loadPlugin("RenderSystem_GL");
    root->setRenderSystem(*root->getAvailableRenderers().begin());
    ResourceGroupManager::getSingleton().addResourceLocation(PATH,"FileSystem","General",true);
    overlaySystem=new OverlaySystem();
    root->initialise(false);
    window = root->createRenderWindow(core::name,core::width,core::height,core::fullscreen);
    smgr = root->createSceneManager();
    smgr->addRenderQueueListener(overlaySystem);
    Camera *cam = smgr->createCamera("");
    cam->setNearClipDistance(5);
    cam->setFarClipDistance(100);
    camNode = smgr->getRootSceneNode()->createChildSceneNode();
    camNode->attachObject(cam);
    viewport = window->addViewport(cam);
    viewport->setClearEveryFrame(true);
    stateManager=new StateManager(this);
    inputManager = new InputManager(this,window);
}

void GameManager::update() {
    root->renderOneFrame();
    stateManager->update();
    inputManager->update();
}

void GameManager::addGuiRect(GuiRect *r){}

void GameManager::removeGuiRect(GuiRect *r){}

void GameManager::removeAllGuiRects(){}

void GameManager::addGuiText(GuiText *t){}

void GameManager::removeGuiText(GuiText *t){}

void GameManager::removeAllGuiTexts(){}

bool GameManager::isRunning(){
    return running;
}

void GameManager::setIsRunning(bool r){
    running=r;
}

InputManager* GameManager::getInputManager() {
    return inputManager;
}

SceneManager* GameManager::getSceneManager() {
    return smgr;
}

StateManager* GameManager::getStateManager() {
    return stateManager;
}

RenderWindow* GameManager::getWindow() {
    return window;
}

Root* GameManager::getRoot() {
    return root;
}
