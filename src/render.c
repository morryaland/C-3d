#include "render.h"
#include <stdlib.h>
#include <X11/Xlib.h>

int init_render()
{
  int ret;
  ret = init_window();

}

int init_xwindow()
{
  XCreateSimpleWindow(Display *, Window, int, int, unsigned int, unsigned int, unsigned int, unsigned long, unsigned long)
}
