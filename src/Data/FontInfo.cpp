//
//  FontInfo.cpp
//  FontViewer
//
//  Created by PAVEL PEREKHOZHIKH on 04.12.2021.
//

#include "FontInfo.hpp"

namespace FontViewer {
    namespace Data {
        FT_Library  library;
        bool libraryInited = false;
        FontInfo::FontInfo(const std::string& fileName) {
            if (!libraryInited) {
                FT_Error error = FT_Init_FreeType( &library );
                if (error) {
                    return;
                }
            }
        }
    }
}
