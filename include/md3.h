#ifndef __MD3_H__
#define __MD3_H__

#include <stdio.h>
#include "3d_mach.h"

#define MD3_MAGIC "IDP3"
#define MAX_QPATH 64
#define MD3_MAX_FRAMES 1024
#define MD3_MAX_TAGS 16
#define MD3_MAX_SURFACES 32
#define MD3_MAX_SHADERS 256
#define MD3_MAX_VERTS 4096
#define MD3_MAX_TRIANGLES 8192
#define MD3_XYZ_SCALE (1.0/64)

typedef char	U8;	
typedef short	S16;
typedef int	S32;	
typedef float	F32;
typedef vec3_t	VEC3;

typedef struct md3_header_s {
  S32 ident;
  S32 version;
  U8  name[MAX_QPATH];
  S32 flags;
  S32 num_frames;
  S32 num_tags;
  S32 num_surfaces;
  S32 num_skins;
  S32 ofs_frames;
  S32 ofs_tags;
  S32 ofs_surfaces;
  S32 ofs_eof;
} md3_header_t;

typedef struct md3_frame_s {
  VEC3 min_bounds;
  VEC3 max_bounds;
  VEC3 local_origin;
  F32  radius;
  U8   name[16];
} md3_frame_t;

typedef struct md3_tag_s {
  U8   name[MAX_QPATH];
  VEC3 origin;
  VEC3 axis[3];
} md3_tag_t;

typedef struct md3_surface_header_s {
  S32 ident;
  U8  name[MAX_QPATH];
  S32 flags;
  S32 num_frames;
  S32 num_shaders;
  S32 num_verts;
  S32 num_triangles;
  S32 ofs_triangles;
  S32 ofs_shaders;
  S32 ofs_st;
  S32 ofs_xyznormal;
  S32 ofs_end;
} md3_surface_header_t;

typedef struct md3_shader_s {
  U8  name[MAX_QPATH];
  S32 shader_index;
} md3_shader_t;

typedef struct md3_triangle_s {
  S32 indexes[3];
} md3_triangle_t;

typedef struct md3_tex_coord_s {
  F32 st[2];
} md3_tex_coord_t;

typedef struct md3_vertex_s {
  S16 x;
  S16 y;
  S16 z;
  S16 normal;
} md3_vertex_t;

typedef struct md3_surface_s {
  md3_surface_header_t header;
  md3_shader_t *shaders;
  md3_triangle_t *triangles;
  md3_tex_coord_t *tex_coords;
  md3_vertex_t *vertexs;
} md3_surface_t;

typedef struct md3_s {
  md3_header_t header;
  md3_frame_t *frames;
  md3_tag_t *tags;
  md3_surface_t *surfaces;
} md3_t;

md3_t *md3_load_file(char *path);
void md3_free(md3_t *md3);

md3_header_t md3_read_header(FILE *fp);
md3_frame_t   *md3_read_frames  (FILE *fp, S32 ofs, S32 num);
md3_tag_t     *md3_read_tags    (FILE *fp, S32 ofs, S32 num);
md3_surface_t *md3_read_surfaces(FILE *fp, S32 ofs, S32 num);

md3_surface_header_t md3_read_surface_header(FILE *fp, S32 ofs);
md3_shader_t    *md3_read_shaders   (FILE *fp, S32 ofs, S32 num);
md3_triangle_t  *md3_read_triangles (FILE *fp, S32 ofs, S32 num);
md3_tex_coord_t *md3_read_tex_coords(FILE *fp, S32 ofs, S32 num);
md3_vertex_t    *md3_read_vertexs   (FILE *fp, S32 ofs, S32 num);

#endif
