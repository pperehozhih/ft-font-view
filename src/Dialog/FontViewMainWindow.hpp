//
//  FontViewMainWindow.hpp
//  FontViewer
//
//  Created by PAVEL PEREKHOZHIKH on 03.12.2021.
//

#ifndef FontViewMainWindow_hpp
#define FontViewMainWindow_hpp

#include <imgui.h>
#include <imgui-glfw.h>
#include <string>

namespace FontViewer {
    namespace GUI {
        class MainDialogInfo {
        public:
            virtual void OnGUI() = 0;
            virtual bool IsVisiable() const = 0;
        };
        class MainDialog {
        public:
            void Update() {
                UpdateMenu();
            }
        private:
            void UpdateMenu() {
                ImGui::BeginMainMenuBar();
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("Open")) {
                        std::string font_name = OpenFile();
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }
            std::string OpenFile();
        };
    }
}

#endif /* FontViewMainWindow_hpp */
