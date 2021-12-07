#pragma once

#include "FontViewMainWindow.hpp"

namespace FontViewer {
	namespace GUI {
		class FaceInfo : public MainDialogInfo
		{
		public:
			FaceInfo(const Data::FontInfoPtr& info):_info(info){}
			virtual void OnGUI() override {
				ImGui::Begin("Font info");
				if (_info) {
					UpdateFaceInfo();
				}
				ImGui::End();
			}
			virtual bool IsVisiable() const override{
				return _info.get() != nullptr;
			}
			void UpdateFaceInfo();
		private:
			Data::FontInfoPtr _info;
		};
	}
}
