#pragma once

#include <GLFW/glfw3.h>
#include <stdint.h>
struct mc_window {
  int32_t hight;
  int32_t width;
};

struct mc_ctx {
  GLFWwindow *glfw_window;
  struct mc_window window;
};

extern struct mc_ctx mc;
