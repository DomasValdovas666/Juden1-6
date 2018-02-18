#pragma once
#ifndef SLIDER_H
#define SLIDER_H

#include"Button.h"
#include"Textbox.h"
#include<OIS.h>

using namespace Ogre;

namespace game {
    namespace gui {
        class Slider {
        public:
            Slider(OIS::Mouse*,SceneManager*,Vector2, Vector2, double, double);
            ~Slider();
            void update();
            void addTextbox(Textbox*);
            double getMinValue();
            double getValue();
            double getMaxValue();
            double getIncrement();
            void setValue(double);
            void setIncrement(double);
            void remove();
            Vector2 getPos();
            Vector2 getSize();
            Textbox* getTextbox();
        private:
            class MovableSliderButton : public Button {
            public:
                MovableSliderButton(Slider*,OIS::Mouse*, SceneManager*,Vector2, Vector2, string, bool);
                void onClick();
                void update();
            private:
                Slider *slider;
                OIS::Mouse *mouse;
                bool clicked = false;
            };
            class StaticSliderButton : public Button {
            public:
                StaticSliderButton(Slider*,OIS::Mouse*, SceneManager*,Vector2, Vector2, string, bool);
                void onClick();
            private:
                Slider *slider;
                OIS::Mouse *mouse;
            };
            MovableSliderButton *movableSliderButton;
            StaticSliderButton *staticSliderButton;
            double minValue, value, maxValue, increment = .1;
            Vector2 pos, size;
            Textbox *textbox = nullptr;
        public:
            MovableSliderButton* getMovableSliderButton();
            StaticSliderButton* getStaticSliderButton();
        };
    }
}

#endif
