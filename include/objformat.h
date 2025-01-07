#ifndef objformat_h
#define objformat_h

#include "3d_mach.h"

enum cstype_e {
  bmatrix,
  bezier,
  bspline,
  cardinal,
  taylor
};

typedef struct objformat_s {
/* Grouping */
  char **g; /* group name */ //TODO
  veci_t s; /* smoothing group */ //TODO
  vec_t *mg; /* merging group */ //TODO
  char *o; /* object name */ //TODO
/* Display/render attributes */
  bool bevel; /* bevel interpolation */ //TODO
  bool c_interp; /* color interpolation */ //TODO
  bool d_interp; /* dissolve interpolation */ //TODO
  veci_t lod; /* level of detail */ //TODO
  char *usemap; /* map name */ //TODO
  char *maplib; /* map library */ //TODO
  char *usemtl; /* material name */ //TODO
  char *mtllib; /* material library */ //TODO
  char *shadow_obj; /* shadow casting */ //TODO
  char *trace_obj; /* ray tracing */ //TODO
  //ctech; /* curve approximation technique */ //TODO
  //stech; /* surface approximation technique */ //TODO
/* Vertex data */
  vec4_t *v; /* geometric vertices */ //TODO
  vec3_t *vt; /* texture vertices */ //TODO
  vec3_t *vn; /* vertex normals */ //TODO
  vec3_t *vp; /* parameter space vertices */ //TODO
/* Free-form curve/surface attributes */
  enum cstype_e cstype; /* rational or non-rational forms of curve or surface type: basis matrix, Bezier, B-spline, Cardinal, Taylor */ //TODO
  veci2_t deg; /* degree */ //TODO
  vec_t *bmatu; /* basis matrix */ //TODO
  vec_t *bmatv; /* basis matrix */ //TODO
  veci2_t step; /* step size */ //TODO
/* Elements */
  veci_t  *p; /* point */ //TODO
  veci2_t *l; /* line */ //TODO
  veci3_t *f; /* face */ //TODO
  vec_t *curv; /* curve */ //TODO
  vec_t curv2; /* 2D curve */ //TODO
  struct { vec_t s0; vec_t s1; vec_t t0; vec_t t1; vec3_t *f; int f_c; } *surf; /* surface */ //TODO
/* Free-form curve/surface body statements */
  vec_t *parmu; /* parameter values */ //TODO
  vec_t *parmv; /* parameter values */ //TODO
  vec_t *trim; /* outer trimming loop */ //TODO
  vec_t *hole; /* inner trimming loop */ //TODO
  vec_t *scrv; /* special curve */ //TODO
  veci_t *sp; /* special point */ //TODO
/* Connectivity between free-form surfaces */
  //con; /* connect */ //TODO
  int mg_c, v_c, vt_c, vn_c, vp_c, 
      p_c, l_c, f_c, curv_c, curv2_c, 
      surf_c, parmu_c, parmv_c, trim_c, 
      hole_c, scrv_c;
} objformat_t;

#endif
