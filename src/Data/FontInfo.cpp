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
            FT_Error error;
            if (!libraryInited) {
                error = FT_Init_FreeType(&library);
                if (error) {
                    return;
                }
                libraryInited = true;
            }
            error = FT_New_Face(library, fileName.c_str(), 0, &_face);
            if (error) {
                return;
            }
            _faceOpened = true;
            _name = _face->family_name;
        }
        FontInfo::~FontInfo() {
            if (_faceOpened) {
                FT_Done_Face(_face);
            }
        }
    }
}
