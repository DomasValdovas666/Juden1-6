#include"AbstractAppState.h"
#include"DefConfigs.h"

namespace game {
    namespace core {
        AbstractAppState::AbstractAppState(GameManager *gM) {
            gameManager=gM;
        }

        void AbstractAppState::update() {
        }

        void AbstractAppState::onAttachment() {
            attached = true;
            int stateId=(int)type;
            for(int i=0;i<bindNumbers[stateId];i++)
                keys.push_back(new Key(binds[stateId][i],triggers[stateId][i],isKey[stateId][i],isAction[stateId][i]));
        }

        void AbstractAppState::onDettachment() {
            attached = false;
        }

        StateType AbstractAppState::getType() {
            return type;
        }

        bool AbstractAppState::isAttached() {
            return attached;
        }

        int AbstractAppState::getNumberOfKeys(){
            return keys.size();
        }

        Key* AbstractAppState::getKey(int i){
            return keys[i];
        }

        GameManager* AbstractAppState::getGameManager() {
            return gameManager;
        }

        void AbstractAppState::onAction(string bind, bool isPressed) {
        }

        void AbstractAppState::onAnalog(string bind, float str) {
        }
    }
}
