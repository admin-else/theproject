#include "mc/err.h"
#include <mc/mc.h>
#include <mc/window.h>
#include <stdio.h>

struct mc_error error = {0};
struct mc_ctx mc = {0};

int main(void) {
  // "Load" settings
  mc.window.hight = 600;
  mc.window.width = 800;

  mc_init_window();
  scanf("no: \n");
  printf("Hello, World!\n");
  return 0;
}
