#include "window.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <string>

using namespace std;
using Application::Window;

Window::Window(int width, int height) {
  this->width = width;
  this->height = height;
}

Window::~Window() {
  if (this->window == nullptr) return;
  glfwDestroyWindow(this->window);
}

void Window::SetKeyCallback(void (*callback)(GLFWwindow* window, int key, int scancode, int action, int mods)) {
  glfwSetKeyCallback(this->window, callback);
}

bool Window::GetShouldClose() {
  if (this->window == nullptr)
    throw "Cannot get status of a window that does not exist"s;

  return glfwWindowShouldClose(this->window);
}

void Window::Create(GLFWmonitor* monitor) {
  if (this->window != nullptr) throw "Window already exists"s;

  monitor =
    monitor != nullptr
    ? monitor
    : glfwGetPrimaryMonitor();

  this->window = glfwCreateWindow(this->width, this->height, WINDOW_DEFAULT_TITLE, monitor, nullptr);
  if (!this->window) throw "Unable to initialize window"s;
}


void Window::Spawn() {
  if (!this->window) {
    throw "Window needs to be created before it can spawn"s;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwMakeContextCurrent(this->window);
}

void Window::Run() {
  glfwSwapBuffers(this->window);
  glfwPollEvents();
}


// --- Window Manipulation ---

int Window::GetHeight() {
  return this->height;
}

void Window::SetHeight(int height) {
  // not only Set the var, but also update the window
  this->height = height;
  // this->window Set height?
}

int Window::GetWidth() {
  return this->width;
}

void Window::SetWidth(int width) {
  // not only Set the var, but also update the window
  this->width = width;
  // this->window Set width?
}

// --- End Window Manipulation ---

