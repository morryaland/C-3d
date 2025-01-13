#ifndef __MD3_TOOLS_H__
#define __MD3_TOOLS_H__

#include "3d_mach.h"

void md3_push  (int *entity, const vec3_t dist);
void md3_rotate(int *entity, float angle, basis_t basis);

#endif
