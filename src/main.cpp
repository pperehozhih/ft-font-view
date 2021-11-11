#include <imgui.h>
#include <imgui-glfw.h>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "TextEditor.h"

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main() {
       // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#else
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui + GLFW example", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    if (!ImGui::GLFW::Init(window)) {
        return -1;
    }
    ImGui::GLFW::UpdateFontTexture();
    bool show_demo_window = true;
    bool show_another_window = true;
    TextEditor text;
    text.SetImGuiChildIgnored(true);
    text.SetLanguageDefinition(TextEditor::LanguageDefinition::JS());
    while (!glfwWindowShouldClose(window)) {
      glfwPollEvents();

      // Start the Dear ImGui frame
      ImGui::GLFW::NewFrame();
      
      
      ImGui::ShowDemoWindow();
        text.Render("info");
      
      ImGui::Begin("Hello, world!");
      ImGui::Button("Look at this pretty button");
      ImGui::End();
      ImGui::Render();
      ImGui::GLFW::Render(window);

      glfwSwapBuffers(window);
   }
   
   ImGui::GLFW::Shutdown();

   glfwDestroyWindow(window);
   glfwTerminate();
   return 0;

}
