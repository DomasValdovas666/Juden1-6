#pragma once
#ifndef DEFCONFIGS_H
#define DEFCONFIGS_H

#include <string>
#include <OIS.h>

using namespace std;

namespace game{
    namespace core {
        static const string PATH="/home/dominykas/c++/Juden1-6-master/Assets/",name="Juden1,6";
        static int width=800,height=600,fullscreen=0,win32=0;

        static const int stateNumber=3,maxBindNumber=3;
        static const int bindNumbers[stateNumber]{1,0,0};
        static const string binds[stateNumber][maxBindNumber]{
            {
                "leftClick"
            },
            {

            },
            {

            }
        };
        static const int triggers[stateNumber][maxBindNumber]{
            {
                (int)OIS::MouseButtonID::MB_Left
            },
            {
            },
            {
            }
        };
        static const int isKey[stateNumber][maxBindNumber]{
            {
                0
            },
            {

            },
            {

            }
        };
        static const int isAction[stateNumber][maxBindNumber]{
            {
                1
            },
            {

            },
            {

            }
        };
        static const string key[stateNumber][maxBindNumber]{
            {
                "LeftClick"
            },
            {

            },
            {

            }
        };
    }
}

#endif /* DEFCONFIGS_H */

