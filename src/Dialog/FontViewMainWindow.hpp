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
#include <map>
#include <filesystem>
#include "../Data/FontInfo.hpp"
#include "Style.hpp"

namespace FontViewer {
    namespace GUI {
        class MainDialogInfo {
        public:
            virtual void OnGUI() = 0;
            virtual bool IsVisiable() const = 0;
        };
        typedef std::shared_ptr<MainDialogInfo> MainDialogInfoPtr;
        class MainDialog {
        public:
            MainDialog() {
#ifdef __APPLE__
#elif WIN32
                std::filesystem::directory_iterator end_itr;
                for (std::filesystem::directory_iterator itr("c:\\Windows\\Fonts");
                    itr != end_itr;
                    ++itr)
                {
                    Data::FontInfo font(itr->path().string());
                    if (font.getFontName().empty() == false) {
                        _systemFont[font.getFontName()] = itr->path().string();
                    }
                }
#endif
            }
            void Update() {
                UpdateMenu();
            }
        private:
            void UpdateMenu() {
                ImGui::BeginMainMenuBar();
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("Open")) {
                        std::string font_name = OpenFile();
                        if (font_name.empty() == false) {
                            _currentFont = std::make_shared<Data::FontInfo>(font_name);
                            UpdateInfo();
                        }
                    }
                    if (ImGui::BeginMenu("System Font")) {
                        for (auto&& font : _systemFont) {
                            if (ImGui::MenuItem(font.first.c_str())) {
                                _currentFont = std::make_shared<Data::FontInfo>(font.second);
                                UpdateInfo();
                            }
                            if (ImGui::IsItemHovered()) {
                                ImGui::BeginTooltip();
                                ImGui::LabelText("##System Font Tooltip", font.second.c_str());
                                ImGui::EndTooltip();
                            }
                        }
                        ImGui::EndMenu();
                    }
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Theme")) {
                    if (ImGui::MenuItem("Dark")) {
                        ImGui::StyleColorsDark();
                    }
                    if (ImGui::MenuItem("Light")) {
                        ImGui::StyleColorsLight();
                    }
                    if (ImGui::MenuItem("Gray")) {
                        ImGui::GrayStyle();
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
                for (auto&& info : _infos) {
                    if (info->IsVisiable()) {
                        info->OnGUI();
                    }
                }
            }
            void UpdateInfo();
            std::string OpenFile();
        private:
            std::map<std::string, std::string> _systemFont;
            std::vector< MainDialogInfoPtr> _infos;
            Data::FontInfoPtr _currentFont;
        };
    }
}

#endif /* FontViewMainWindow_hpp */
