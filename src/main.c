#include "md3.h"
#include "render.h"

int main(int argc, char* argv[]) {
  md3_t *mesh = md3_load_file(argv[1]);
  printf("%s\n", (char*)&mesh->header.ident);
  printf("%d\n", mesh->header.version);
  printf("%s\n", mesh->header.name);
  printf("fl %d\n", mesh->header.flags);
  printf("fn %d\n", mesh->header.num_frames);
  printf("tn %d\n", mesh->header.num_tags);
  printf("sn %d\n", mesh->header.num_surfaces);
  printf("skn %d\n", mesh->header.num_skins);
  printf("%d\n", mesh->header.ofs_frames);
  printf("%d\n", mesh->header.ofs_tags);
  printf("%d\n", mesh->header.ofs_surfaces);
  printf("%d\n", mesh->header.ofs_eof);
  putchar('\n');
  printf("%f %f %f\n", mesh->frames[0].min_bounds[0], mesh->frames[0].min_bounds[1], mesh->frames[0].min_bounds[2]);
  printf("%f %f %f\n", mesh->frames[0].max_bounds[0], mesh->frames[0].max_bounds[1], mesh->frames[0].max_bounds[2]);
  printf("%f %f %f\n", mesh->frames[0].local_origin[0], mesh->frames[0].local_origin[1], mesh->frames[0].local_origin[2]);
  printf("%f\n", mesh->frames[0].radius);
  printf("%s\n", mesh->frames[0].name);
  putchar('\n');
  printf("%s\n", mesh->tags[0].name);
  printf("%f %f %f\n", mesh->tags[0].origin[0], mesh->tags[0].origin[1], mesh->tags[0].origin[2]);
  printf("%f %f %f\n", mesh->tags[0].axis[0][0], mesh->tags[0].axis[0][1], mesh->tags[0].axis[0][2]);
  printf("%f %f %f\n", mesh->tags[0].axis[1][0], mesh->tags[0].axis[1][1], mesh->tags[0].axis[1][2]);
  printf("%f %f %f\n", mesh->tags[0].axis[2][0], mesh->tags[0].axis[2][1], mesh->tags[0].axis[2][2]);
  putchar('\n');
  printf("%s\n", (char*)&mesh->surfaces[0].header.ident);
  printf("%s\n", mesh->surfaces[0].header.name);
  printf("fl %d\n", mesh->surfaces[0].header.flags);
  printf("fn %d\n", mesh->surfaces[0].header.num_frames);
  printf("sn %d\n", mesh->surfaces[0].header.num_shaders);
  printf("vn %d\n", mesh->surfaces[0].header.num_verts);
  printf("tn %d\n", mesh->surfaces[0].header.num_triangles);
  printf("%d\n", mesh->surfaces[0].header.ofs_triangles);
  printf("%d\n", mesh->surfaces[0].header.ofs_shaders);
  printf("%d\n", mesh->surfaces[0].header.ofs_st);
  printf("%d\n", mesh->surfaces[0].header.ofs_xyznormal);
  printf("%d\n", mesh->surfaces[0].header.ofs_end);
  md3_free(mesh);
  for(;;);
  return 0;
}
