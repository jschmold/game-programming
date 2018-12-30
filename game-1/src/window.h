#ifndef _H_WINDOW
#define _H_WINDOW

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

using std::string;

#define WINDOW_DEFAULT_TITLE "Game One"

namespace Application
{
  class Window
  {

  private:
    int width = 1920;
    int height = 1080;
    GLFWwindow* window;
    void (*keyCallback) (GLFWwindow* window, int key, int scancode, int action, int modifiers);

  public:

    Window(int width, int height);
    ~Window();

    int GetWidth();
    void SetWidth(int width);

    int GetHeight();
    void SetHeight(int height);

    void SetKeyCallback(void (*callback)(GLFWwindow* window, int key, int scancode, int action, int mods));

    // A getter for whether or not the window should close
    bool GetShouldClose();

    /**
     * Create a new window
     */
    void Create(GLFWmonitor* monitor = nullptr);

    /**
     * Set the current OpenGL context
     */
    void Spawn();

    void Run();
  };
}


#endif
