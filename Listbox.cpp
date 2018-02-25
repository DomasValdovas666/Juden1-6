#include"Listbox.h"
#include"GuiAppState.h"
#include"DefConfigs.h"

using namespace Ogre;

namespace game {
    namespace gui {
        Listbox::ListboxButton::ListboxButton(Listbox *l, SceneManager *smgr,Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr,pos, size, name, separate) {
            listbox = l;
        }

        void Listbox::ListboxButton::onClick() {
            if (!listbox->isOpen())
                listbox->openUp();
            else
                listbox->close();
        }

        Listbox::ScrollingButton::ScrollingButton(SceneManager *smgr,Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr,pos, size, name, separate) {
        }

        void Listbox::ScrollingButton::onClick() {

        }

        Listbox::Listbox(OIS::Mouse *mouse,SceneManager *smgr,Vector2 pos, Vector2 size, std::vector<string> lines, int maxDisplay) {
            this->mouse=mouse;
            this->pos = pos;
            this->size = size;
            this->maxDisplay = maxDisplay;
            for (int i = 0; i < lines.size(); i++) {
                this->lines.push_back(new GuiText(Vector2(pos.x,pos.y+size.y*i),lines[i]));
                this->lines[i]->toggleDisplay(false);
            }
            this->lines[0]->toggleDisplay(true);
            listboxButton = new ListboxButton(this, smgr,pos, size, "ListboxButton", false);
            scrollingButton = new ScrollingButton(smgr,Vector2(pos.x + size.x - 20, pos.y + 20), Vector2(20, 20.0 * (maxDisplay - 2) / (lines.size() - maxDisplay)), "scrollingButton", false);
            selRect=new GuiRect(smgr,pos,size,ColourValue(.6,.35,.05));
            selRect->toggleDisplay(false);
        }

        Listbox::~Listbox() {
        }

        void Listbox::update() {
            //IGUIFont *font = gameManager->getDevice()->getGUIEnvironment()->getFont(PATH + "Fonts/fontcourier.bmp");
            if (open) {
                //gameManager->getDevice()->getVideoDriver()->draw2DRectangle(*listboxButton->getColor(), rect<s32>(pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y * maxDisplay), nullptr);
                int mousePosY = mouse->getMouseState().Y.abs;
                Vector2 p=pos;
                if (mousePosY>pos.y&&mousePosY<pos.y+size.y*maxDisplay)
                    p.y=pos.y+size.y*((int)(mousePosY-pos.y)/((int)size.y));
                else if (mousePosY < pos.y)
                    p.y=pos.y;
                else
                    p.y=pos.y+size.y*(maxDisplay-1);
                selRect->setPos(p);
                for (int i = 0; i < maxDisplay; i++) {
                    //font->draw(lines[i + scrollOffset], rect<s32>(pos.X, pos.Y + size.Y*i, pos.X + size.X, pos.Y + size.Y * (i + 1)), SColor(255, 255, 255, 255));
                }
                if (scrollOffset > 0) {
                    //scroll
                    Vector2 scrollingButtonPos = scrollingButton->getPos();
                    scrollingButtonPos.y = pos.y + 20 + scrollingButton->getSize().y * (scrollOffset - 1);
                    scrollingButton->setPos(scrollingButtonPos);
                    Vector2 p=scrollingButtonPos-scrollingButton->getPos();
                    scrollingButton->moveButton(p.x,p.y);
                }
                /*
                gameManager->getDevice()->getVideoDriver()->draw2DRectangle(SColor(255, 150, 150, 150), rect<s32>(
                        scrollingButton->getPos().X, scrollingButton->getPos().Y, scrollingButton->getPos().X + scrollingButton->getSize().X,
                        scrollingButton->getPos().Y + scrollingButton->getSize().Y));
                 */
            } else {
                //first
               // gameManager->getDevice()->getVideoDriver()->draw2DRectangle(*listboxButton->getColor(), rect<s32>(pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y), nullptr);
                //font->draw(lines[scrollOffset], rect<s32>(pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y), SColor(255, 255, 255, 255));
            }
        }

        void Listbox::openUp() {
            open = true;
            Vector2 size = listboxButton->getSize();
            size.y *= maxDisplay;
            listboxButton->setSize(size);
            selRect->toggleDisplay(true);
            for(int i=scrollOffset;i<scrollOffset+maxDisplay;i++)
                lines[i]->toggleDisplay(true);
        }

        void Listbox::close() {
            open = false;
            Vector2 size = listboxButton->getSize();
            size.y /= maxDisplay;
            listboxButton->setSize(size);
            selRect->toggleDisplay(false);
            for(int i=scrollOffset+1;i<scrollOffset+maxDisplay;i++)
                lines[i]->toggleDisplay(false);
        }

        void Listbox::scrollUp() {
            if (scrollOffset > 0){
                scrollOffset--;
                for(int i=0;i<lines.size();i++) {
                    Vector2 p=lines[i]->getPos();
                    lines[i]->setPos(Vector2(p.x,p.y-size.y*(i+1)));
                }
            }
        }

        void Listbox::scrollDown() {
            if (scrollOffset < lines.size() - maxDisplay) {
                scrollOffset++;
                for(int i=0;i<lines.size();i++) {
                    Vector2 p=lines[i]->getPos();
                    lines[i]->setPos(Vector2(p.x,p.y-size.y*(i-1)));
                }
            }
        }

        Listbox::ListboxButton* Listbox::getListboxButton() {
            return listboxButton;
        }

        Listbox::ScrollingButton* Listbox::getScrollingButton() {
            return scrollingButton;
        }

        bool Listbox::isOpen() {
            return open;
        }
        /*
        void Listbox::appendLines(std::vector<string>& lines) {
            for (int i = 0; i < this->lines.size(); i++)
                lines.push_back(this->lines[i]);
        }

        std::vector<string> Listbox::getContents() {
            return lines[];
        }
        */

        int Listbox::getSelectedOption() {
            return selectedOption;
        }

        void Listbox::addLine(string line) {
            GuiText *t=new GuiText(Vector2(pos.x,pos.y-size.y*lines.size()),line);
            lines.push_back(t);
        }

        void Listbox::changeLine(int id, string newLine) {
            lines[id]->setEntry(newLine);
        }

        void Listbox::remove(){
            for(int i=0;i<lines.size();i++)
                lines[i]->remove();
            selRect->remove();
            delete this;
        }
    }
}
