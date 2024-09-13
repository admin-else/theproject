#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <mc/err.h>
#include <mc/mc.h>
#include <stdlib.h>

void mc_framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  if (mc.glfw_window != window)
    return;
  glViewport(0, 0, width, height);
  mc.window.width = width;
  mc.window.hight = height;
}

void mc_init_window() {
  MC_ERR_MUST(glfwInit() == GL_TRUE, MC_ERR_GLFW, init);
  mc.glfw_window =
      glfwCreateWindow(mc.window.width, mc.window.hight, "Craft", NULL, NULL);
  MC_ERR_MUST(mc.glfw_window != NULL, MC_ERR_GLFW, window_create);
  glfwSetWindowSizeCallback(mc.glfw_window, mc_framebuffer_size_callback);

  return;
err_window_create:
  glfwTerminate();
err_init:
}

// Cleans up everything
void mc_free_window() { glfwTerminate(); }
