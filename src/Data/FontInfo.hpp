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
        };
        typedef std::shared_ptr<FontInfo> FontInfoPtr;
    }
}

#endif /* FontInfo_hpp */
