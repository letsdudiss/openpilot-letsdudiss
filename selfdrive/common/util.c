#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void* read_file(const char* path, size_t* out_len) {
  FILE* f = fopen(path, "r");
  if (!f) {
    return NULL;
  }
  fseek(f, 0, SEEK_END);
  long f_len = ftell(f);
  rewind(f);

  char* buf = calloc(f_len + 1, 1);
  assert(buf);

  size_t num_read = fread(buf, f_len, 1, f);
  fclose(f);

  if (num_read != 1) {
    return NULL;
  }

  if (out_len) {
    *out_len = f_len + 1;
  }

  return buf;
}
