#include"Button.h"
#include"DefConfigs.h"

using namespace Ogre;

namespace game {
    namespace gui {
        Button::Button() {
        }

        Button::Button(SceneManager *smgr,Vector2 pos, Vector2 size, std::string name, bool separate, string imagePath) {
            this->smgr=smgr;
            this->name = name;
            this->pos = pos;
            this->size = size;
            this->separate = separate;
            this->imageButton=imageButton;
            if(imagePath==""){
                color = new ColourValue(.5, .5, .5);
                rect = new GuiRect(smgr,pos, size, *color);
            }
            else
                rect= new GuiRect(smgr,pos,size,imagePath);
            if (separate)
                text = new GuiText(pos, name);
        }


        void Button::onClick() {
        }

        void Button::update() {
            /*
            IVideoDriver *driver = gameManager->getDevice()->getVideoDriver();
            if (!imageButton) {
                driver->draw2DRectangle(*color, rect<s32>(pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y), nullptr);
                if (separate) {
                    IGUIFont *font = gameManager->getDevice()->getGUIEnvironment()->getFont(PATH + "Fonts/fontcourier.bmp");
                    font->draw(name, rect<s32>(pos.X + size.X / 4 + textXOffset, pos.Y + size.Y / 4 + textYOffset, size.X, size.Y), SColor(255, 250, 250, 250));
                }
            } else
                driver->draw2DImage(image->getImage(), pos);
             */
        }

        void Button::moveButton(int x, int y) {
            pos.x += x;
            pos.y += y;
            rect->setPos(pos);
            if(text)
                moveText(x, y);
        }

        void Button::moveText(int x, int y) {
            textXOffset += x;
            textYOffset += y;
            text->setPos(pos+Vector2(textXOffset,textYOffset));
        }

        Vector2 Button::getPos() {
            return pos;
        }

        void Button::setPos(Vector2 p) {
            pos = p;
        }

        Vector2 Button::getSize() {
            return size;
        }

        void Button::setSize(Vector2 s) {
            size = s;
            rect->setSize(s);
        }

        ColourValue* Button::getColor() {
            return color;
        }

        void Button::setColor(ColourValue *c) {
            color = c;
        }

        string Button::getName() {
            return name;
        }

        void Button::setName(string n) {
            name = n;
        }

        bool Button::isSeparate() {
            return separate;
        }

        bool Button::isImageButton() {
            return imageButton;
        }

        void Button::remove() {
            delete color;
            rect->remove();
            if(text)
                text->remove();
            delete this;
        }
    }
}
