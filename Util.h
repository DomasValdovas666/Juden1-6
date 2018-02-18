#pragma once
#ifndef UTIL_H
#define UTIL_H

#include<time.h>
#include<string>
#include"vector"
#include<Ogre.h>
#include<fstream>

using namespace std;

namespace game {
    namespace util {
        typedef unsigned short u16;
        typedef unsigned int u32;
        typedef unsigned long long u64;
        typedef short s16;
        typedef int s32;
        typedef long long s64;
        inline s64 getTime(){
            return 1000*time(0);
        }
        string getAdress(void*);
        std::vector<double> convCoords(Ogre::Vector2, Ogre::Vector2);
        void readFile(string);
        void writeFile(string);
    }
}

#endif /* UTIL_H */

