#include"Textbox.h"
#include"DefConfigs.h"
#include"Util.h"

using namespace Ogre;
using namespace game::util;

namespace game {
    namespace gui {
        Textbox::TextboxButton::TextboxButton(Textbox *t, SceneManager *smgr,Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr,pos,size, name, separate) {
            textbox = t;
        }

        void Textbox::TextboxButton::onClick() {
            if (!textbox->isEnabled())
                textbox->enable();
            else
                textbox->disable();
        }

        Textbox::Textbox(SceneManager *smgr,Vector2 pos, Vector2 size) {
            this->pos = pos;
            this->size = size;
            textboxButton = new TextboxButton(this, smgr,pos, size, "TextboxButton", false);
            cursorRect=new GuiRect(smgr,pos,Vector2(cursorWidth,size.y),ColourValue(.4,.4,.4));
            //font = gameManager->getDevice()->getGUIEnvironment()->getFont(PATH + "Fonts/bigfont.png");
        }

        void Textbox::update() {
            //gameManager->getDevice()->getVideoDriver()->draw2DRectangle(SColor(255, 200, 200, 200), rect<s32>(pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y), nullptr);
            //font->draw(entry, rect<s32>(pos.X, pos.Y - 8, pos.X + size.X, pos.Y - 8 + size.Y), SColor(255, 255, 255, 255));
            if (enabled) {
                if (canChangeCursor()) {
                    canShowCursor = !canShowCursor;
                    lastBlinkTime = getTime();
                    cursorRect->toggleDisplay(canShowCursor);
                }
            }
        }

        void Textbox::type(wchar_t ch) {
            /*
            if (!capitalLeters)
                ch = tolower(ch);
            else
                ch = toupper(ch);
            std::vector<wchar_t> v;
            for (int i = 0; i < entry.size(); i++)
                v.push_back(entry[i]);
            v.insert(v.end() - cursorPosOffset, ch);
            entry += 0;
            for (int i = 0; i < v.size(); i++)
                entry[i] = v[i];
             */
        }

        void Textbox::moveCursor(bool left) {
            Vector2 p=cursorRect->getPos();
            if (left && entry.size() - cursorPosOffset > 0){
                cursorPosOffset++;
                cursorRect->setPos(Vector2(p.x-cursorWidth,p.y));
            }
            else if (!left && cursorPosOffset > 0){
                cursorPosOffset--;
                cursorRect->setPos(Vector2(p.x+cursorWidth,p.y));
            }
        }

        void Textbox::deleteCharacter() {
            if (cursorPosOffset != entry.size()) {
                std::vector<wchar_t> v;
                for (int i = 0; i < entry.size(); i++)
                    v.push_back(entry[i]);
                v.erase(v.end() - 1 - cursorPosOffset);
                entry.erase(entry.size() - 1);
                for (int i = 0; i < v.size(); i++)
                    entry[i] = v[i];
            }
        }

        bool Textbox::canChangeCursor() {
            if (getTime() - lastBlinkTime > 250)
                return true;
            else
                return false;
        }

        void Textbox::enable() {
            enabled = true;
            lastBlinkTime = getTime();
            cursorRect->toggleDisplay(true);
        }

        void Textbox::disable() {
            enabled = false;
            cursorRect->toggleDisplay(false);
        }

        void Textbox::remove(){
            textboxButton->remove();
            cursorRect->remove();
            delete this;
        }

        bool Textbox::isEnabled() {
            return enabled;
        }

        Textbox::TextboxButton* Textbox::getTextboxButton() {
            return textboxButton;
        }

        string Textbox::getEntry() {
            return entry;
        }

        void Textbox::setEntry(string entry) {
            this->entry = entry;
        }

        bool Textbox::isCapitalLeters() {
            return capitalLeters;
        }

        void Textbox::setIsCapitalLeters(bool capitalLeters) {
            this->capitalLeters = capitalLeters;
        }
        /*
        void Textbox::setFont(IGUIFont *font) {
            this->font = font;
        }
         */
    }
}
