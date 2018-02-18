#pragma once
#ifndef KEY_H
#define KEY_H

#include<string>

using namespace std;

namespace game{
    namespace core{
        class Key{
        public:
            Key(string,int,bool,bool);
            ~Key(){}
            string getBind();
            int getTrigger();
            bool isAction();
            bool isKey();
            bool isPressed();
            bool isUsedBefore();
            void setIsPressed(bool);
            void setUsedBefore(bool);
        private:
            string bind;
            int trigger;
            bool action,key,pressed=false,usedBefore=false;
        };
    }
}

#endif /* KEY_H */

