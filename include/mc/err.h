#pragma once

#include <mc/util.h>
#include <stdint.h>

#define MC_ERRS_X                                                              \
  X(MC_ERR_NO)                                                                 \
  X(MC_ERR_GL)                                                                 \
  X(MC_ERR_GLFW)
enum mc_error_type {
#define X(err) err,
  MC_ERRS_X
#undef X
};

struct mc_error {
  enum mc_error_type type;
  const char *file;
  int32_t line;
  char *message;
  bool should_free_message;
};

extern struct mc_error error;

const char *mc_error_type_to_str(enum mc_error_type data);
void print_error_info();

#define MC_ERR_RAISE(err_type, msg)                                            \
  do {                                                                         \
    error = (struct mc_error){.type = err_type,                                \
                              .file = __FILE__,                                \
                              .line = __LINE__,                                \
                              .message = msg,                                  \
                              .should_free_message = false};                   \
  } while (0)

#define MC_ERR_MUST(expr, err_type, msg)                                       \
  if (!(expr)) {                                                               \
    MC_ERR_RAISE(err_type, #msg);                                              \
    goto err_##msg;                                                            \
  }
