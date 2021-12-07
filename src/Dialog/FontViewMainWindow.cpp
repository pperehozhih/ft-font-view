//
//  FontViewMainWindow.cpp
//  FontViewer
//
//  Created by PAVEL PEREKHOZHIKH on 03.12.2021.
//

#include "FontViewMainWindow.hpp"
#include <nfd.hpp>
#include "FaceInfo.hpp"

namespace FontViewer {
    namespace GUI {
        std::string MainDialog::OpenFile() {
            NFD_Init();
            std::string result_str;
            nfdchar_t *outPath;
            nfdfilteritem_t filterItem[2] = { { "Font file", "ttf,ttc,fnt,woff,woff2,otf" } };
            nfdresult_t result = NFD_OpenDialog(&outPath, filterItem, 1, NULL);
            if (result == NFD_OKAY)
            {
                result_str = outPath;
                NFD_FreePath(outPath);
            }
            NFD_Quit();
            return result_str;
        }
        void MainDialog::UpdateInfo() {
            _infos.clear();
            _infos.push_back(std::make_shared<FaceInfo>(_currentFont));
        }
    }
}
