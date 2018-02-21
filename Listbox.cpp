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
            for (int i = 0; i < lines.size(); i++)
                GuiText *t=new GuiText(Vector2(pos.x,pos.y-size.y*i),lines[i]);
            listboxButton = new ListboxButton(this, smgr,pos, size, "ListboxButton", false);
            scrollingButton = new ScrollingButton(smgr,Vector2(pos.x + size.x - 20, pos.y + 20), Vector2(20, 20.0 * (maxDisplay - 2) / (lines.size() - maxDisplay)), "scrollingButton", false);
            selRect=new GuiRect(smgr,pos,size,ColourValue(.5,.5,0));
        }

        Listbox::~Listbox() {
        }

        void Listbox::update() {
            //IGUIFont *font = gameManager->getDevice()->getGUIEnvironment()->getFont(PATH + "Fonts/fontcourier.bmp");
            if (open) {
                //gameManager->getDevice()->getVideoDriver()->draw2DRectangle(*listboxButton->getColor(), rect<s32>(pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y * maxDisplay), nullptr);
                int mousePosY = mouse->getMouseState().Y.abs;
                for (int i = 0; i < maxDisplay; i++) {
                    Vector2 p=pos;
                    if (mousePosY > pos.y + size.y * i && mousePosY < pos.y + size.y * (i + 1))
                        p.y=pos.y+size.y*(i-1);
                        //gameManager->getDevice()->getVideoDriver()->draw2DRectangle(SColor(255, 200, 125, 0), rect<s32>(pos.X, pos.Y + size.Y * i, pos.X + size.X - 20, pos.Y + size.Y * (i + 1)), nullptr);
                    else if (mousePosY < pos.y)
                        p.y=pos.y;
                        //gameManager->getDevice()->getVideoDriver()->draw2DRectangle(SColor(255, 200, 125, 0), rect<s32>(pos.X, pos.Y, pos.X + size.X - 20, pos.Y + size.Y), nullptr);
                    else if (mousePosY > pos.y + size.y * maxDisplay)
                        p.y=pos.y+size.y*(maxDisplay-1);
                    //gameManager->getDevice()->getVideoDriver()->draw2DRectangle(SColor(255, 200, 125, 0), rect<s32>(pos.X, pos.Y + size.Y * (maxDisplay - 1), pos.X + size.X - 20, pos.Y + size.Y * (maxDisplay + 0)), nullptr);
                    selRect->setPos(p);
                }
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
            size.y *= 3;
            listboxButton->setSize(size);
            /*
            for(int i=scrollOffset;i<scrollOffset+maxDisplay;i++)
                lines[i]->setCol(1,1,1,1);
             */
        }

        void Listbox::close() {
            open = false;
            Vector2 size = listboxButton->getSize();
            size.y /= 3;
            listboxButton->setSize(size);
            /*
            for(int i=0;i<lines.size();i++){
                if(i==scrollOffset)
                    lines[i]->setCol(1,1,1,1);
                else
                    lines[i]->setCol(1,1,1,0);
            }
             */
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
            listboxButton->remove();
            scrollingButton->remove();
            selRect->remove();
            delete this;
        }
    }
}
