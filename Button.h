#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include<Ogre.h>
#include"GuiText.h"
#include"GuiRect.h"
#include"DefConfigs.h"
#include"Util.h"

using namespace std;
using namespace game::core;
using namespace Ogre;
using namespace game::util;

namespace game {
    namespace gui {
        class Button {
        public:
            Button();
            Button(SceneManager*,Vector2, Vector2, string, bool, string="");
            ~Button(){}
            virtual void onClick();
            virtual void update();
            virtual void moveText(int, int);
            virtual void moveButton(int, int);
            void remove();
            //void setImageButton(Image*);
            Vector2 getPos();
            Vector2 getSize();
            void setPos(Vector2);
            void setSize(Vector2);
            ColourValue* getColor();
            void setColor(ColourValue*);
            string getName();
            void setName(string);
            bool isSeparate();
            bool isImageButton();
            SceneNode* getNode();
            //Image* getImage();
        private:
            //Image *image = nullptr;
            GuiRect *rect;
            GuiText *text=nullptr;
            bool separate = true, imageButton;
            int textXOffset = 0, textYOffset = 0;
        protected:
            SceneManager *smgr;
            std::string name;
            Vector2 pos, size;
            ColourValue *color=nullptr;
        };
    }
}

#endif
