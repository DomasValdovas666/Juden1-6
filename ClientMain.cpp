#include"GameManager.h"
#include"GuiAppState.h"
#include"ClientMain.h"
#include"OptionsButton.h"
#include"ExitButton.h"
#include"GuiText.h"
#include<Ogre.h>
#include<string>
#include<iostream>

using namespace game;
using namespace core;
using namespace net;
using namespace Ogre;
using namespace std;

class PlayButton : public gui::Button{
    public:
        PlayButton(SceneManager *smgr, Vector2 pos, Vector2 size,string name,bool separate) : gui::Button(smgr,pos,size,name,separate){}
        void onClick(){
            std::cout<<"AAAA\n";
        }
};


int main() {
    GameManager *g = new GameManager();
    GuiAppState *guiState= new GuiAppState(g);
    g->getStateManager()->attachState(guiState);
    guiState->addButton(new PlayButton(g->getSceneManager(),Vector2(0,0),Vector2(100,30),"Play",true));
    guiState->addButton(new OptionsButton(g,guiState,g->getSceneManager(),Vector2(0,40),Vector2(100,30),"Options",true));
    //guiState->addButton(new ExitButton(g,g->getSceneManager(),Vector2(0,80),Vector2(100,30),"Exit",true));
    while (g->isRunning()&&!g->getWindow()->isClosed()) g->update();
    return 0;
}

namespace game{
    namespace net {
    }
}
