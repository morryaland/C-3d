#include "3d_mach.h"

void rotate_vec3(vec3_t vec, vec3_t angle)
{
  float x = angle[0];
  float y = angle[1];
  float z = angle[2];
  float asis[3][3] = {
    {cos(y)*cos(z),-cos(y)*sin(z),sin(y)},
    {sin(x)*sin(y)*cos(z)+cos(x)*sin(z),-sin(x)*sin(y)*sin(z)+cos(x)*cos(z),-sin(x)*cos(y)},
    {-cos(x)*sin(y)*cos(z)+sin(x)*sin(z),cos(x)*sin(y)*sin(z)+sin(x)*cos(z),cos(x)*cos(y)}};
  mul_Matrix3x3_on_vec3(asis, vec, vec);
}

void mul_Matrix3x3( float mtx1[3][3], float mtx2[3][3], float mtxres[3][3] )
{
mtxres[0][0] = mtx1[0][0] * mtx2[0][0] + mtx1[0][1] * mtx2[1][0] + mtx1[0][2] * mtx2[2][0];
mtxres[0][1] = mtx1[0][0] * mtx2[0][1] + mtx1[0][1] * mtx2[1][1] + mtx1[0][2] * mtx2[2][1];
mtxres[0][2] = mtx1[0][0] * mtx2[0][2] + mtx1[0][1] * mtx2[1][2] + mtx1[0][2] * mtx2[2][2];
mtxres[1][0] = mtx1[1][0] * mtx2[0][0] + mtx1[1][1] * mtx2[1][0] + mtx1[1][2] * mtx2[2][0];
mtxres[1][1] = mtx1[1][0] * mtx2[0][1] + mtx1[1][1] * mtx2[1][1] + mtx1[1][2] * mtx2[2][1];
mtxres[1][2] = mtx1[1][0] * mtx2[0][2] + mtx1[1][1] * mtx2[1][2] + mtx1[1][2] * mtx2[2][2];
mtxres[2][0] = mtx1[2][0] * mtx2[0][0] + mtx1[2][1] * mtx2[1][0] + mtx1[2][2] * mtx2[2][0];
mtxres[2][1] = mtx1[2][0] * mtx2[0][1] + mtx1[2][1] * mtx2[1][1] + mtx1[2][2] * mtx2[2][1];
mtxres[2][2] = mtx1[2][0] * mtx2[0][2] + mtx1[2][1] * mtx2[1][2] + mtx1[2][2] * mtx2[2][2];
}

void mul_Matrix3x3_on_vec3( float mtx[3][3], const vec3_t vec, vec3_t out )
{
    out[0] = mtx[0][0] * vec[0] + mtx[0][1] * vec[1] + mtx[0][2] * vec[2];
    out[1] = mtx[1][0] * vec[0] + mtx[1][1] * vec[1] + mtx[1][2] * vec[2];
    out[2] = mtx[2][0] * vec[0] + mtx[2][1] * vec[1] + mtx[2][2] * vec[2];
}

void sum_vec3( const vec3_t a, const vec3_t b, vec3_t out ) {
    out[0] = a[0] + b[0];
    out[1] = a[1] + b[1];
    out[2] = a[2] + b[2];
}

void div_vec3( const vec3_t a, const vec3_t b, vec3_t out ) {
    out[0] = a[0] / b[0];
    out[1] = a[1] / b[1];
    out[2] = a[2] / b[2];
}

void sub_vec3( const vec3_t a, const vec3_t b, vec3_t out ) {
    out[0] = a[0] - b[0];
    out[1] = a[1] - b[1];
    out[2] = a[2] - b[2];
}

void mul_vec3( const vec3_t a, const vec3_t b, vec3_t out ) {
    out[0] = a[0] * b[0];
    out[1] = a[1] * b[1];
    out[2] = a[2] * b[2];
}

void mul_vec2( const vec2_t a, const vec2_t b, vec2_t out ) {
    out[0] = a[0] * b[0];
    out[1] = a[1] * b[1];
}

void copy_vec3( vec3_t changed,const vec3_t source ) {
    memcpy( changed, source, sizeof( vec3_t ) );
}

void push_vec3( vec3_t vec, const vec3_t dist )
{
    vec[0] += dist[0];
    vec[1] += dist[1];
    vec[2] += dist[2];
}

void move_vec3( vec3_t vec, const vec3_t coords )
{
    vec[0] = coords[0];
    vec[1] = coords[1];
    vec[2] = coords[2];
}

void norm_vec3( vec3_t vec )
{
    float qsqrt = 1 / sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
    vec[0] *= qsqrt;
    vec[1] *= qsqrt;
    vec[2] *= qsqrt;
}
