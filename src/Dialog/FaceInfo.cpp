#include "FaceInfo.hpp"

namespace FontViewer {
	namespace GUI {
		void FaceInfo::UpdateFaceInfo() {
			ImGui::LabelText("Face name", "%s", _info->getFontName().c_str());
		}
	}
}
