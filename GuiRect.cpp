#include"GuiRect.h"
#include"Button.h"

namespace game {
    namespace gui {
        GuiRect::GuiRect(SceneManager *smgr,Vector2 pos, Vector2 size,ColourValue color) {
            this->smgr=smgr;
            this->pos=pos;
            this->size=size;
            matName=util::getAdress(this)+"Mat";
            setupRect();
            rect->setMaterial(setupColorMat(color));
        }

        GuiRect::GuiRect(SceneManager *smgr,Vector2 pos, Vector2 size, string imagePath) {
            this->smgr=smgr;
            this->pos=pos;
            this->size=size;
            matName=util::getAdress(this)+"Mat";
            setupRect();
            rect->setMaterial(setupImageMat(imagePath));
        }

        MaterialPtr GuiRect::setupImageMat(string imagePath){
            Ogre::MaterialPtr mat = MaterialManager::getSingleton().create(matName, "General");
            Pass *pass = mat->getTechnique(0)->getPass(0);
            pass->createTextureUnitState(imagePath);
            pass->setDepthCheckEnabled(false);
            pass->setDepthWriteEnabled(false);
            pass->setLightingEnabled(true);
            return mat;
        }

        MaterialPtr GuiRect::setupColorMat(ColourValue color){
            MaterialPtr mat = MaterialManager::getSingleton().create(matName, "General");
            Pass *pass = mat->getTechnique(0)->getPass(0);
            pass->setDepthCheckEnabled(false);
            pass->setDepthWriteEnabled(false);
            pass->setLightingEnabled(true);
            pass->setSelfIllumination(color);
            return mat;
        }

        void GuiRect::setupRect(){
            rect=new Ogre::Rectangle2D(true);
            std::vector<double> convPos=util::convCoords(pos,size);
            rect->setCorners(convPos[0],convPos[1],convPos[2],convPos[3]);
            AxisAlignedBox aab;
            aab.setInfinite();
            rect->setBoundingBox(aab);
            node=smgr->getRootSceneNode()->createChildSceneNode();
            node->attachObject(rect);
        }

        void GuiRect::toggleDisplay(bool display) {
            node->setVisible(display);
            //display ? overlay->show() : overlay->hide();
        }

        void GuiRect::remove() {
            smgr->getRootSceneNode()->removeChild(node);
            node->detachObject(rect);
            Ogre::MaterialManager::getSingleton().unload(matName,"General");
            Ogre::MaterialManager::getSingleton().remove(matName,"General");
            delete rect;
            delete this;
        }

        Vector2 GuiRect::getPos() {
            return pos;
        }

        Vector2 GuiRect::getSize() {
            return size;
        }

        void GuiRect::setPos(Vector2 p) {
            pos = p;
            std::vector<double> convPos=util::convCoords(pos,size);
            rect->setCorners(convPos[0],convPos[1],convPos[2],convPos[3]);
        }

        void GuiRect::setSize(Vector2 s) {
            size = s;
            std::vector<double> convPos=util::convCoords(pos,size);
            rect->setCorners(convPos[0],convPos[1],convPos[2],convPos[3]);
        }

        ColourValue GuiRect::getColor() {
            return ColourValue::ZERO;
        }

        void GuiRect::setColor(ColourValue c) {
        }

        void GuiRect::setZOrder(int zOrder){

        }

        int GuiRect::getZOrder() {
            return 0;
        }
    }
}
