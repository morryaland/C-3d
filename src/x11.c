#include "x11.h"

#if HAVE_LIBX11

void create_xwindow()
{
  XOpenDisplay("0:");
}

#endif
