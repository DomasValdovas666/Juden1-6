#include"Util.h"
#include<sstream>
#include"DefConfigs.h"

using namespace game::core;

namespace game {
    namespace util {
        string getAdress(void *ptr){
            const void *adr=static_cast<void*>(ptr);
            stringstream ss;
            ss<<adr;
            return ss.str();
        }

        string getTimeStr(){
            stringstream ss;
            ss<<getTime();
            return ss.str();
        }

        std::vector<double> convCoords(Ogre::Vector2 pos,Ogre::Vector2 size) {
            std::vector<double> coords;
            coords.push_back(-1+2*pos.x/width);
            coords.push_back(1-2*pos.y/height);
            coords.push_back(-1+2*(pos.x+size.x)/width);
            coords.push_back(1-2*(pos.y+size.y)/height);
            return coords;
        }

        void readFile(string path) {}

        void writeFile(string path) {}
    }
}
