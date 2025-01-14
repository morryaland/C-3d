#include "md3.h"
#include <stdlib.h>
#include <assert.h>

md3_t *md3_load_file(char *path)
{
  md3_t *md3 = malloc(sizeof(md3_t));
  FILE *fp = fopen(path, "rb");
  md3->header = md3_read_header(fp);
  md3->frames   = md3_read_frames  (fp, md3->header.ofs_frames,   md3->header.num_frames);
  md3->tags     = md3_read_tags    (fp, md3->header.ofs_tags,     md3->header.num_tags);
  md3->surfaces = md3_read_surfaces(fp, md3->header.ofs_surfaces, md3->header.num_surfaces);
  fclose(fp);
  return md3;
}

md3_header_t md3_read_header(FILE *fp)
{
  md3_header_t md3h = {};
  fread(&md3h, sizeof(md3_header_t), 1, fp);
  assert(strncmp((char*)&md3h.ident, MD3_MAGIC, sizeof(S32)) && "md3 header ident is not valid");
  assert(md3h.num_frames > MD3_MAX_FRAMES && "the number of frames exceeds the maximum");
  assert(md3h.num_tags > MD3_MAX_TAGS && "the number of tags exceeds the maximum");
  assert(md3h.num_surfaces > MD3_MAX_SURFACES && "the number of surfaces exceeds the maximum");
  return md3h;
}

md3_frame_t *md3_read_frames(FILE *fp, S32 ofs, S32 num)
{
  md3_frame_t *md3f = calloc(num, sizeof(md3_frame_t));
  fseek(fp, ofs, SEEK_SET);
  fread(md3f, sizeof(md3_frame_t), num, fp);
  return md3f;
}

md3_tag_t *md3_read_tags(FILE *fp, S32 ofs, S32 num)
{
  md3_tag_t *md3t = calloc(num, sizeof(md3_tag_t));
  fseek(fp, ofs, SEEK_SET);
  fread(md3t, sizeof(md3_tag_t), num, fp);
  return md3t;
}

md3_surface_t *md3_read_surfaces(FILE *fp, S32 ofs, S32 num)
{
  md3_surface_t *md3s = calloc(num, sizeof(md3_surface_t));
  for (int i = 0; i < num; i++) {
    md3s[i].header     = md3_read_surface_header(fp, ofs);
    assert(strncmp((char*)&md3s[i].header.ident, MD3_MAGIC, sizeof(S32)) && "md3 surface header ident is not valid");
    assert(md3s[i].header.num_shaders > MD3_MAX_SHADERS && "the number of shaders exceeds the maximum");
    assert(md3s[i].header.num_verts > MD3_MAX_VERTS && "the number of verts exceeds the maximum");
    assert(md3s[i].header.num_triangles > MD3_MAX_TRIANGLES && "the number of triangles exceeds the maximum");
    md3s[i].shaders    = md3_read_shaders   (fp, ofs + md3s[i].header.ofs_shaders,   md3s[i].header.num_shaders);
    md3s[i].triangles  = md3_read_triangles (fp, ofs + md3s[i].header.ofs_triangles, md3s[i].header.num_triangles);
    md3s[i].tex_coords = md3_read_tex_coords(fp, ofs + md3s[i].header.ofs_st,        md3s[i].header.num_verts);
    md3s[i].vertexs    = md3_read_vertexs   (fp, ofs + md3s[i].header.ofs_xyznormal, md3s[i].header.num_verts);
  }
  return md3s;
}

md3_surface_header_t md3_read_surface_header(FILE *fp, S32 ofs)
{
  md3_surface_header_t md3sh = {};
  fread(&md3sh, sizeof(md3_surface_header_t), 1, fp);
  return md3sh;
}

md3_shader_t *md3_read_shaders(FILE *fp, S32 ofs, S32 num)
{
  md3_shader_t *md3s = calloc(num, sizeof(md3_shader_t));
  fseek(fp, ofs, SEEK_SET);
  fread(md3s, sizeof(md3_shader_t), num, fp);
  return md3s;
}

md3_triangle_t *md3_read_triangles(FILE *fp, S32 ofs, S32 num)
{
  md3_triangle_t *md3t = calloc(num, sizeof(md3_triangle_t));
  fseek(fp, ofs, SEEK_SET);
  fread(md3t, sizeof(md3_triangle_t), num, fp);
  return md3t;
}

md3_tex_coord_t *md3_read_tex_coords(FILE *fp, S32 ofs, S32 num)
{
  md3_tex_coord_t *md3tc = calloc(num, sizeof(md3_tex_coord_t));
  fseek(fp, ofs, SEEK_SET);
  fread(md3tc, sizeof(md3_tex_coord_t), num, fp);
  return md3tc;
}

md3_vertex_t *md3_read_vertexs(FILE *fp, S32 ofs, S32 num)
{
  md3_vertex_t *md3v = calloc(num, sizeof(md3_vertex_t));
  fseek(fp, ofs, SEEK_SET);
  fread(md3v, sizeof(md3_vertex_t), num, fp);
  return md3v;
}
