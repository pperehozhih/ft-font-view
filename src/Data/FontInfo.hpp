//
//  FontInfo.hpp
//  FontViewer
//
//  Created by PAVEL PEREKHOZHIKH on 04.12.2021.
//

#ifndef FontInfo_hpp
#define FontInfo_hpp

#include <memory>
#include <string>
#include <vector>
#include <ft2build.h>
#include FT_FREETYPE_H

namespace FontViewer {
    namespace Data {
        class FontInfo{
        public:
            FontInfo(const std::string& fileName);
            const std::string& getFontName() const {
                return _name;
            }
            virtual ~FontInfo();
        private:
            FT_Face _face;
            std::string _name;
            bool _faceOpened = false;
        };
        typedef std::shared_ptr<FontInfo> FontInfoPtr;
    }
}

#endif /* FontInfo_hpp */
