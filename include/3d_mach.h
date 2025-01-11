#ifndef user_h
#define user_h

#include <math.h>
#include <string.h>

#ifndef M_PI
/* number PI */
#define M_PI 3.14159265358979323846f
#endif

/* existing bases */
typedef enum basis_s {
    Xasis,
    Yasis,
    Zasis
} basis_t;

/* vectors */
typedef float vec_t  [1];
typedef int   veci_t [1];
typedef float vec2_t [2];
typedef int   veci2_t[2];
typedef float vec3_t [3];
typedef int   veci3_t[3];
typedef float vec4_t [4];
typedef int   veci4_t[4];

/* multiplication matrix 3x3 */
void mul_Matrix3x3(float mtx1[3][3], float mtx2[3][3], float mtxres[3][3]);

/* vector operations */
void sum_vec3(const vec3_t a, const vec3_t b, vec3_t out);
void div_vec3(const vec3_t a, const vec3_t b, vec3_t out);
void sub_vec3(const vec3_t a, const vec3_t b, vec3_t out);
void mul_vec3(const vec3_t a, const vec3_t b, vec3_t out);
void mul_vec2(const vec2_t a, const vec2_t b, vec2_t out);

/* vector interaction */
void copy_vec3  (vec3_t changed, const vec3_t source);
void rotate_vec3(vec3_t vec, float angle, basis_t basis);
void move_vec3  (vec3_t vec, const vec3_t coords);
void push_vec3  (vec3_t vec, const vec3_t dist);
void norm_vec3  (vec3_t vec);

/* multiplication matrix 3x3 on vector 3 */
void mul_Matrix3x3_on_vec3(float mtx[3][3], const vec3_t vec, vec3_t out);

#endif
