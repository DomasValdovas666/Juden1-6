#ifndef FONTDATA_H
#define FONTDATA_H

#include<string>
#include"DefConfigs.h"

namespace game {
    namespace core {
        static const int numberOfFonts=1;
        static const std::string fontName[numberOfFonts]{"batangFont"};
        static const std::string fontPath[numberOfFonts]{core::PATH+"Fonts/batang.ttf"};
    }
}

#endif // FONTDATA_H
