#ifndef __X11_H__
#define __X11_H__

#include "config.h"

#if HAVE_LIBX11

#include <X11/Xlib.h>

#define create_window() init_xwindow()

void create_xwindow();

#endif /*HAVE_LIBX11*/

#endif /*x11_h*/
