#include <GLFW/glfw3.h>
#include "mc/err.h"

void init_window() {
    MC_MUST(glfwInit() == GL_TRUE, MC_ERR_GLFW)

}
