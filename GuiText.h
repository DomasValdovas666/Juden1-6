#pragma once
#ifndef GUITEXT_H
#define GUITEXT_H

#include"Util.h"
#include<string>
#include<Ogre.h>
#include<Overlay/OgreFont.h>
#include<Overlay/OgreFontManager.h>
#include<Overlay/OgreOverlay.h>
#include<Overlay/OgreOverlayManager.h>
#include<Overlay/OgreOverlayContainer.h>
#include<Overlay/OgreTextAreaOverlayElement.h>

using namespace Ogre;
using namespace std;

namespace game {
    namespace gui {
        class GuiText{
        public:
            GuiText(Vector2,string="");
            ~GuiText(){}
            void setPos(Vector2);
            Vector2 getPos();
            void setEntry(string);
            string getEntry();
            ColourValue getColor();
            void setColor(ColourValue);
            Real getCharHeight();
            void setCharHeigh(Real);
            void toggleDisplay(bool);
            void remove();
        private:
            Vector2 pos;
            FontPtr font;
            OverlayContainer *panel;
            Overlay *overlay;
            TextAreaOverlayElement *textArea;
        };
    }
}

#endif /* GUITEXT_H */

