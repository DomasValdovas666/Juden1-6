#include"GuiText.h"
#include"DefConfigs.h"

using namespace Ogre;

namespace game {
    namespace gui {
        GuiText::GuiText(Vector2 pos,string entry){
            string fontName=util::getAdress(this)+"Font";
            font = FontManager::getSingleton().create(fontName, "General");
            font->setType(FT_TRUETYPE);
            font->setSource(core::PATH+"Fonts/batang.ttf");
            font->setTrueTypeSize(30);
            font->setTrueTypeResolution(30);
            font->setParameter("size", "26");
            font->setParameter("resolution", "96");
            font->load();
            OverlayManager &man=OverlayManager::getSingleton();
            overlay=man.create(util::getAdress(this)+"Overlay");
            panel=static_cast<OverlayContainer*>(man.createOverlayElement("Panel",util::getAdress(this)+"Pan"));
            panel->setMetricsMode(GMM_PIXELS);
            panel->setPosition(pos.x,pos.y);
            panel->setDimensions(1,1);
            panel->show();
            textArea = static_cast<TextAreaOverlayElement*> (man.createOverlayElement("TextArea", util::getAdress(this)+"Text"));
            textArea->setMetricsMode(GMM_PIXELS);
            textArea->setDimensions(1,1);
            textArea->setPosition(0,0);
            textArea->setFontName(fontName);
            textArea->setCaption(entry);
            textArea->setCharHeight(30);
            textArea->setColour(ColourValue::White);
            overlay->add2D(panel);
            panel->addChild(textArea);
            overlay->show();
        }

        void GuiText::toggleDisplay(bool display) {
            display ? overlay->show() : overlay->hide();
        }

        void GuiText::remove() {
            overlay->hide();
            panel->hide();
            textArea->hide();
            overlay->remove2D(panel);
            /*
            delete &font;
            delete textArea;
            delete panel;
            delete overlay;
             */
            delete this;
        }

        Vector2 GuiText::getPos(){
            return pos;
        }

        void GuiText::setPos(Ogre::Vector2 p){
            pos=p;
            textArea->setPosition(pos.x,pos.y);
        }

        string GuiText::getEntry() {
            return textArea->getCaption();
        }

        void GuiText::setEntry(string e) {
            textArea->setCaption(e);
        }

        ColourValue GuiText::getColor() {
            return textArea->getColour();
        }

        void GuiText::setColor(ColourValue c) {
            textArea->setColour(c);
        }

        Real GuiText::getCharHeight() {
            return textArea->getCharHeight();
        }

        void GuiText::setCharHeigh(Real h) {
            textArea->setCharHeight(h);
        }
    }
}
