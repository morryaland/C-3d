#ifndef render_h
#define render_h

#include "3d_mach.h"
#include "world.h"

/* console window resolution */
#ifndef H_SCREEN
#define H_SCREEN 149
#endif
#ifndef W_SCREEN
#define W_SCREEN 250
#endif

/* filling the screen buffer with spaces */
void clean_screen( char screen[] );

/* 3d to 2d projection */
void screen_proection( world_t *myworld, camera_t *camera, vec2_t screen[] );

/* drawing lines on the screen buffer */
void print_line2d( const vec2_t a, const vec2_t b, char screen[] );

#endif
