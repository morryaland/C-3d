#include "world.h"
#include "render.h"
#include "objformat.h"

int main(int argc, char* argv[]) {
  objformat_t *obj = obj_load_file(argv[1]);
  return 0;
}
