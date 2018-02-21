#include"OptionsButton.h"
#include"DefConfigs.h"
#include"ExitButton.h"

using namespace game::core;
using namespace Ogre;

namespace game {
    namespace gui {
        OptionsButton::OkButton::OkButton(GameManager *gM,GuiAppState *state, SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr, pos, size, name, separate) {
            this->state = state;
            gameManager=gM;
        }

        void OptionsButton::OkButton::onClick() {

        }

        OptionsButton::DefaultsButton::DefaultsButton(GameManager *gM,GuiAppState *state, SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr, pos, size, name, separate) {
            this->state = state;
            gameManager=gM;
        }

        void OptionsButton::DefaultsButton::onClick() {

        }

        OptionsButton::BackButton::BackButton(GameManager *gM,GuiAppState *state, SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr, pos, size, name, separate) {
            this->state = state;
            gameManager=gM;
        }

        void OptionsButton::BackButton::onClick() {
            gameManager->removeAllGuiTexts();
            gameManager->removeAllGuiRects();
            state->removeAllListboxes();
            state->removeAllCheckboxes();
            state->removeAllSliders();
            state->removeAllTextboxes();
            state->removeButton("Ok");
            state->removeButton("Defaults");
            OptionsButton *optionsButton = new OptionsButton(gameManager,state, smgr, Vector2(0,0), Vector2(0,0), "Options", true);
            optionsButton->onClick();
            state->removeButton("Back");
            state->addButton(new ExitButton(gameManager,smgr,Vector2(0,200),Vector2(100,40),"Exit",true));
        }

        OptionsButton::TabButton::TabButton(GameManager *gM,GuiAppState *state, SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr, pos, size, name, separate) {
            this->state = state;
            gameManager=gM;
        }

        void OptionsButton::TabButton::onClick() {
            state->removeButton("Back");
            OkButton *okButton = new OkButton(gameManager,state, smgr, Vector2(50, height - 150), Vector2(140, 50), "Ok", true);
            DefaultsButton *defaultsButton = new DefaultsButton(gameManager,state, smgr, Vector2(200, height - 150), Vector2(140, 50), "Defaults", true);
            BackButton *returnButton = new BackButton(gameManager,state, smgr, Vector2(350, height - 150), Vector2(140, 50), "Back", true);
            state->addButton(okButton);
            state->addButton(defaultsButton);
            state->addButton(returnButton);
        }

        OptionsButton::ControlsTab::ControlsTab(GameManager *gM,GuiAppState *state, SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : TabButton(gM,state, smgr, pos, size, name, separate) {
            this->state = state;
            gameManager=gM;
        }

        void OptionsButton::ControlsTab::onClick() {
            TabButton::onClick();
            std::vector<string> lines;
            lines.push_back("A");
            lines.push_back("B");
            lines.push_back("C");
            lines.push_back("D");
            lines.push_back("E");
            lines.push_back("F");
            lines.push_back("G");
            lines.push_back("H");
            lines.push_back("I");
            lines.push_back("J");
            Listbox *listbox = new Listbox(gameManager->getInputManager()->getMouse(),smgr, Vector2(width / 4, height / 10), Vector2(360, 20), lines, 5);
            state->addListbox(listbox);
            state->removeButton("Mouse");
            state->removeButton("Video");
            state->removeButton("Audio");
            state->removeButton("Multiplayer");
            state->removeButton("Controls");
        }

        OptionsButton::MouseTab::MouseTab(GameManager *gM,GuiAppState *state, SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : TabButton(gM,state, smgr, pos, size, name, separate) {
            this->state = state;
            gameManager=gM;
        }

        void OptionsButton::MouseTab::onClick() {
            TabButton::onClick();
            Vector2 pos(width / 3, height / 4);
            //IGUIFont *font = gameManager->getDevice()->getGUIEnvironment()->getFont(PATH + "Fonts/fonthaettenschweiler.bmp");
            Slider *mouseSensitivitySlider = new Slider(gameManager->getInputManager()->getMouse(),smgr, Vector2(pos.x, pos.y), Vector2(300, 10), .1, 3.);
            Textbox *mouseSensitivityTextbox = new Textbox(smgr, Vector2(pos.x + 320, pos.y - 10), Vector2(100, 20));
            Checkbox *reverseMouseCheckbox = new Checkbox(smgr, Vector2(pos.x, pos.y + 50));
            gameManager->addGuiText(new GuiText(Vector2(width / 3 - 90, height / 4 - 5), "MouseSensitivity"));
            gameManager->addGuiText(new GuiText(Vector2(width / 3 + 20, height / 4 + 50), "ReverseMouse"));
            state->addTextbox(mouseSensitivityTextbox);
            state->addSlider(mouseSensitivitySlider);
            state->addCheckbox(reverseMouseCheckbox);
            state->removeButton("Controls");
            state->removeButton("Video");
            state->removeButton("Audio");
            state->removeButton("Multiplayer");
            state->removeButton("Mouse");
        }

        OptionsButton::VideoTab::VideoTab(GameManager *gM,GuiAppState *state, SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : TabButton(gM,state, smgr, pos, size, name, separate) {
            this->state = state;
            gameManager=gM;
        }

        void OptionsButton::VideoTab::onClick() {
            TabButton::onClick();
            std::vector<string> lines;
            for (int i = 0; i < 10; i++) {
                string s;
                s += i;
                lines.push_back(s);
            }
            Vector2 pos(width / 3, height / 8);
            Listbox *resolutionsListbox = new Listbox(gameManager->getInputManager()->getMouse(),smgr, Vector2(pos.x, pos.y), Vector2(100, 20), lines, 5);
            Checkbox *fullscreenCheckbox = new Checkbox(smgr, Vector2(pos.x, pos.y + 30));
            Checkbox *vsyncCheckbox = new Checkbox(smgr, Vector2(pos.x, pos.y + 50));
            Checkbox *normalMapCheckbox = new Checkbox(smgr, Vector2(pos.x, pos.y + 70));
            Checkbox *parallaxMapCheckbox = new Checkbox(smgr, Vector2(pos.x, pos.y + 90));
            Checkbox *specularMapCheckbox = new Checkbox(smgr, Vector2(pos.x, pos.y + 110));
            gameManager->addGuiText(new GuiText(Vector2(pos.x + 20, pos.y + 30), "Fullscreen"));
            gameManager->addGuiText(new GuiText(Vector2(pos.x + 20, pos.x + 50), "VSync"));
            gameManager->addGuiText(new GuiText(Vector2(pos.x + 20, pos.y + 70), "NormalMap"));
            gameManager->addGuiText(new GuiText(Vector2(pos.x + 20, pos.y + 90), "ParallaxMap"));
            gameManager->addGuiText(new GuiText(Vector2(pos.x + 20, pos.y + 110), "SpecularMap"));
            state->addListbox(resolutionsListbox);
            state->addCheckbox(fullscreenCheckbox);
            state->addCheckbox(vsyncCheckbox);
            state->addCheckbox(normalMapCheckbox);
            state->addCheckbox(parallaxMapCheckbox);
            state->addCheckbox(specularMapCheckbox);
            state->removeButton("Controls");
            state->removeButton("Mouse");
            state->removeButton("Audio");
            state->removeButton("Multiplayer");
            state->removeButton("Video");
        }

        OptionsButton::AudioTab::AudioTab(GameManager *gM,GuiAppState *state, SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : TabButton(gM,state, smgr, pos, size, name, separate) {
            this->state = state;
            gameManager=gM;
        }

        void OptionsButton::AudioTab::onClick() {
            TabButton::onClick();
            Vector2 pos(width / 3, height / 8);
            Slider *volumeSlider = new Slider(gameManager->getInputManager()->getMouse(),smgr, Vector2(pos.x, pos.y), Vector2(300, 10), 0., 2.);
            Textbox *volumeTextbox = new Textbox(smgr, Vector2(pos.x + 320, pos.y), Vector2(100, 20));
            state->addTextbox(volumeTextbox);
            state->addSlider(volumeSlider);
            state->removeButton("Controls");
            state->removeButton("Mouse");
            state->removeButton("Video");
            state->removeButton("Multiplayer");
            state->removeButton("Audio");
        }

        OptionsButton::MultiplayerTab::MultiplayerTab(GameManager *gM, GuiAppState *state, SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : TabButton(gM,state, smgr, pos, size, name, separate) {
            this->state = state;
            gameManager=gM;
        }

        void OptionsButton::MultiplayerTab::onClick() {
            TabButton::onClick();
            Vector2 pos(width / 3, height / 6);
            Textbox *tcpTextbox = new Textbox(smgr, Vector2(pos.x, pos.y), Vector2(100, 20));
            Textbox *udpTextbox = new Textbox(smgr, Vector2(pos.x, pos.y + 30), Vector2(100, 20));
            Textbox *playerNameTextbox = new Textbox(smgr, Vector2(pos.x, pos.y + 60), Vector2(100, 20));
            gameManager->addGuiText(new GuiText(Vector2(pos.x - 50, pos.y), "TCP port"));
            gameManager->addGuiText(new GuiText(Vector2(pos.x - 50, pos.y + 30), "UDP port"));
            gameManager->addGuiText(new GuiText(Vector2(pos.x - 65, pos.y + 60), "Player name"));
            state->addTextbox(tcpTextbox);
            state->addTextbox(udpTextbox);
            state->addTextbox(playerNameTextbox);
            state->removeButton("Controls");
            state->removeButton("Mouse");
            state->removeButton("Video");
            state->removeButton("Audio");
            state->removeButton("Multiplayer");
        }

        OptionsButton::OptionsButton(GameManager *gM,GuiAppState *state, SceneManager *smgr, Vector2 pos, Vector2 size, string name, bool separate) : Button(smgr, pos, size, name, separate) {
            this->state = state;
            gameManager=gM;
        }

        void OptionsButton::onClick() {
            /*
             */
            ControlsTab *controlsTab = new ControlsTab(gameManager,state, smgr, Vector2(width / 4, height / 10), Vector2(100, 50), "Controls", true);
            MouseTab *mouseTab = new MouseTab(gameManager,state, smgr, Vector2(width / 4, height / 10 + 60), Vector2(100, 50), "Mouse", true);
            VideoTab *videoTab = new VideoTab(gameManager,state, smgr, Vector2(width / 4, height / 10 + 120), Vector2(100, 50), "Video", true);
            AudioTab *audioTab = new AudioTab(gameManager,state, smgr, Vector2(width / 4, height / 10 + 180), Vector2(100, 50), "Audio", true);
            MultiplayerTab *mupltiplayerTab = new MultiplayerTab(gameManager,state, smgr, Vector2(width / 4, height / 10 + 240), Vector2(100, 50), "Multiplayer", true);
            state->addButton(controlsTab);
            state->addButton(mouseTab);
            state->addButton(videoTab);
            state->addButton(audioTab);
            state->addButton(mupltiplayerTab);
            state->removeButton("Play");
            state->removeButton("Exit");
            state->removeButton("Options");
        }
    }
}
