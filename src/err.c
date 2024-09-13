#include <execinfo.h>
#include <mc/err.h>
#include <mc/util.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 128

void print_stack_trace() {
  void *buffer[MAX_FRAMES];
  int num_frames;

  num_frames = backtrace(buffer, MAX_FRAMES);

  char **symbols = backtrace_symbols(buffer, num_frames);

  if (symbols == NULL) {
    perror("backtrace_symbols");
    exit(EXIT_FAILURE);
  }

  printf("Stack trace (most recent call last):\n");
  for (int i = 0; i < num_frames; i++) {
    printf("#%d %s\n", i, symbols[i]);
  }

  free(symbols);
}

const char *mc_error_type_to_str(enum mc_error_type data) {
  switch (data) {
#define X(data)                                                                \
  case data:                                                                   \
    return #data;
    MC_ERRS_X
#undef X
  default:
    return "BAD_ERROR_ID";
  }
}

void mc_error_print_info() {
  printf("%s:%d in ERR%d - %s: %s\n", error.file, error.line, error.type,
         mc_error_type_to_str(error.type), MC_NULL_SAFE_STR(error.message));
  print_stack_trace();
}

void mc_error_clear() {
  if (error.should_free_message)
    free(error.message);
  error = (struct mc_error){0};
}
