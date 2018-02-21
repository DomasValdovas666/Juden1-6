#include"Checkbox.h"
#include"DefConfigs.h"

using namespace Ogre;

namespace game {
    namespace gui {
        Checkbox::CheckboxButton::CheckboxButton(Checkbox *ch,SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr,pos, size, name, separate) {
            checkbox = ch;
        }

        void Checkbox::CheckboxButton::onClick() {
            checkbox->check();
        }

        Checkbox::Checkbox(SceneManager *smgr,Vector2 pos) {
            this->pos = pos;
            checkboxButton = new CheckboxButton(this, smgr,pos, Vector2(length, length), "CheckboxButton", false);
            xMark = new GuiText(pos,"X");
            xMark->toggleDisplay(false);
        }

        void Checkbox::update() {
            /*
                IVideoDriver *driver = gameManager->getDevice()->getVideoDriver();
                driver->draw2DRectangle(SColor(255, 100, 100, 100), rect<s32>(pos.X, pos.Y, pos.X + length, pos.Y + length), nullptr);
                if (checked) {
                        driver->draw2DLine(pos, vector2d<s32>(pos.X + length, pos.Y + length),SColor(255,255,255,255));
                        driver->draw2DLine(vector2d<s32>(pos.X,pos.Y+length), vector2d<s32>(pos.X + length, pos.Y), SColor(255, 255, 255, 255));
                }
             */
        }

        void Checkbox::check() {
            checked = !checked;
            xMark->toggleDisplay(checked);
        }

        void Checkbox::remove(){
            xMark->remove();
            checkboxButton->remove();
            delete this;
        }

        bool Checkbox::isChecked() {
            return checked;
        }

        Checkbox::CheckboxButton* Checkbox::getCheckboxButton() {
            return checkboxButton;
        }
    }
}
