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
char *g; /* group name */ //TODO
  s; /* smoothing group */ //TODO
  mg; /* merging group */ //TODO
char *o; /* object name */ //TODO
/* Display/render attributes */
  bevel; /* bevel interpolation */ //TODO
  c_interp; /* color interpolation */ //TODO
  d_interp; /* dissolve interpolation */ //TODO
  lod; /* level of detail */ //TODO
  usemtl; /* material name */ //TODO
  mtllib; /* material library */ //TODO
  shadow_obj; /* shadow casting */ //TODO
  trace_obj; /* ray tracing */ //TODO
  ctech; /* curve approximation technique */ //TODO
  stec; /* surface approximation technique */ //TODO
/* Vertex data */
  vec4_t *v; /* geometric vertices */ //TODO
  int v_c;
  vec3_t *vt; /* texture vertices */ //TODO
  int vt_c;
  vec3_t *vn; /* vertex normals */ //TODO
  int vn_c;
  vec3_t *vp; /* parameter space vertices */ //TODO
  int vp_c;
/* Free-form curve/surface attributes */
  enum cstype_e cstype; /* rational or non-rational forms of curve or surface type: basis matrix, Bezier, B-spline, Cardinal, Taylor */ //TODO
  vec2_t deg; /* degree */ //TODO
  vec_t *bmat; /* basis matrix */ //TODO
  vec2_t step; /* step size */ //TODO
/* Elements */
  p; /* point */ //TODO
  l; /* line */ //TODO
  f; /* face */ //TODO
  curv; /* curve */ //TODO
  curv2; /* 2D curve */ //TODO
  surf; /* surface */ //TODO
/* Free-form curve/surface body statements */
  parm; /* parameter values */ //TODO
  trim; /* outer trimming loop */ //TODO
  hole; /* inner trimming loop */ //TODO
  scrv; /* special curve */ //TODO
  sp; /* special point */ //TODO
  end; /* end statement */ //TODO
/* Connectivity between free-form surfaces */
  con; /* connect */ //TODO
} objformat_t;

#endif
