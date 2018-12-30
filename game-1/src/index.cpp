#include <stdio.h>
#include <iostream>
#include "window.h"

using std::cout;
using std::cin;
using std::endl;
using Application::Window;

void error_handler(int code, const char* description)
{
  cout << "Error with code " << code << endl;
  cout << description;
}

void key_listener(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  fprintf(stdout, "%i %i %i %i", key, scancode, action, mods);
  if (key == GLFW_KEY_E && action == GLFW_PRESS) {
    cout << "Pressed e?";
  }
  if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE) {

    exit(1);
  }
}

int main() {
  if (!glfwInit()) {
    cout << "Unable to load GLFW";
    return -1;
  }

  if (!glewInit())
  {
    cout << "Unable to init GLEW";
    return -1;
  }

  glfwSetErrorCallback(error_handler);

  Window* win = new Window(1920, 1080);
  try {
    win->Create();
    win->SetKeyCallback(key_listener);
    win->Spawn();
  } catch (string err) {
    cout << err << endl;
    return -1;
  }

  while(!win->GetShouldClose()) win->Run();

  glfwTerminate();
  return 0;
}
