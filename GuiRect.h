#pragma once
#ifndef GUIRECT_H
#define GUIRECT_H

#include<string>
#include"Util.h"
#include<OGRE/Ogre.h>
#include<OgreRectangle2D.h>

using namespace Ogre;
using namespace std;

namespace game {
    namespace gui {
        class GuiRect {
        public:
            GuiRect(SceneManager*,Vector2, Vector2,ColourValue);
            GuiRect(SceneManager*,Vector2,Vector2,string);
            ~GuiRect(){}
            void setPos(Vector2);
            void setSize(Vector2);
            Vector2 getPos();
            Vector2 getSize();
            ColourValue getColor();
            void setColor(ColourValue);
            void toggleDisplay(bool);
            virtual void remove();
        private:
            SceneManager *smgr;
            Rectangle2D *rect;
            SceneNode *node;
            Vector2 pos, size;
            MaterialPtr setupImageMat(string);
            MaterialPtr setupColorMat(ColourValue);
            void setupRect();
        };
    }
}

#endif /* GUIRECT_H */

