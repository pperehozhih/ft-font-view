cmake_minimum_required(VERSION 3.13)
project(FontViewer)
set(CMAKE_CXX_STANDARD 17)
if (NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/scpm.cmake)
	file(DOWNLOAD https://raw.githubusercontent.com/pperehozhih/scpm/master/scpm.cmake ${CMAKE_CURRENT_BINARY_DIR}/scpm.cmake)
	#file(DOWNLOAD http://127.0.0.1:8000/scpm.cmake ${CMAKE_CURRENT_BINARY_DIR}/scpm.cmake)
endif()
include(${CMAKE_CURRENT_BINARY_DIR}/scpm.cmake)
#set(scpm_server "http://127.0.0.1:8000/")
#set(scmp_build_type Debug)
set(scpm_imgui_glfw_version docking)
scpm_install(imgui_glfw)
scpm_install(nfd)
include_directories(SYSTEM "${scpm_root_dir}/include")
link_directories("${scpm_root_dir}/lib")
scpm_create_target(TARGET ${PROJECT_NAME} TYPE GUI FILES
	src/main.cpp
	src/TextEditor.cpp
	src/TextEditor.h
	src/Dialog/FontViewMainWindow.cpp
	src/Dialog/FontViewMainWindow.hpp
	src/Data/FontInfo.cpp
	src/Data/FontInfo.hpp
	src/Dialog/FaceInfo.cpp
	src/Dialog/FaceInfo.hpp
)
scpm_link_target(TARGET ${PROJECT_NAME} LIBS imgui_glfw nfd)
scpm_debugger_setup(${PROJECT_NAME})
