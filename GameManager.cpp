#include "GameManager.h"
#include "DefConfigs.h"
#include"FontData.h"

using namespace Ogre;
using namespace game::gui;

namespace game {
    namespace core {
        GameManager::GameManager() {
            root = new Root("plugins.cfg");
            root->loadPlugin("RenderSystem_GL");
            root->setRenderSystem(*root->getAvailableRenderers().begin());
            ResourceGroupManager::getSingleton().addResourceLocation(PATH,"FileSystem","General",true);
            overlaySystem=new OverlaySystem();
            root->initialise(false);
            window = root->createRenderWindow(name,width,height,fullscreen);
            window->setVisible(true);
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
            inputManager = new game::core::InputManager(this,window);
            for(int i=0;i<core::numberOfFonts;i++) {
                Ogre::FontPtr font = Ogre::FontManager::getSingleton().create(core::fontName[i], "General");
                font->setType(FT_TRUETYPE);
                font->setSource(core::fontPath[i]);
                font->setTrueTypeSize(30);
                font->setTrueTypeResolution(30);
                font->setParameter("size", "26");
                font->setParameter("resolution", "96");
                font->load();
                core::fonts.push_back(font);
            }
         }

        void GameManager::update() {
            root->renderOneFrame();
            Ogre::WindowEventUtilities::messagePump();
            stateManager->update();
            inputManager->update();
        }

        void GameManager::addGuiRect(GuiRect *r){
            rectangles.push_back(r);
        }

        void GameManager::removeGuiRect(GuiRect *r){
            bool found=false;
            for(int i=0;i<rectangles.size()&&!found;i++)
                if(rectangles[i]==r){
                    found=true;
                    rectangles[i]->remove();
                    rectangles.erase(rectangles.begin()+i);
                }
        }

        void GameManager::removeAllGuiRects(){
            for(GuiRect *g : rectangles){
                g->remove();
                rectangles.pop_back();
            }
        }

        void GameManager::addGuiText(GuiText *t){
            texts.push_back(t);
        }

        void GameManager::removeGuiText(GuiText *t){
            bool found=false;
            for(int i=0;i<texts.size()&&!found;i++)
                if(texts[i]==t){
                    found=true;
                    texts[i]->remove();
                    texts.erase(texts.begin()+i);
                }
        }

        void GameManager::removeAllGuiTexts(){
            for(GuiText *g : texts){
                g->remove();
                texts.pop_back();
            }
        }

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
    }
}
