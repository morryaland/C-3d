AC_INIT([C-3d],[0.0])
AC_CONFIG_SRCDIR(src/main.c)

AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_MKDIR_P
AC_CANONICAL_HOST

AC_CHECK_HEADERS(
stdbool.h
stdlib.h
stdio.h
math.h
string.h
assert.h
stddef.h
)

AC_ARG_WITH([X11], [  --with-X11 (default)],
            [if test "x$withval" = xyes; then
              with_X11 = yes
              with_wayland = no
            else
              with_X11 = no
            fi], [with_X11=yes])

AC_ARG_WITH([wayland], [  --with-wayland],
            [if test "x$withval" = xyes; then
              with_wayland = yes
              with_cairo = yes
              with_X11 = no
            else
              with_wayland = no
            fi], [with_wayland=no])

AC_ARG_WITH([GL],  [  --with-GL],
            [if test "x$withval" = xyes; then
              with_GL = yes
              with_cairo = no
            else
              with_GL = no
            fi], [with_GL=no])

AC_ARG_WITH([cairo],  [  --with-cairo],
            [if test "x$withval" = xyes; then
              with_cairo = yes
              with_GL = no
            else
              with_cairo = no
            fi], [with_GL=no])

if test "x$with_X11" = xyes && test "x$with_wayland" = xyes; then
  AC_MSG_ERROR([X11 and Wayland support cannot be enabled simultaneously.])
fi

if test "x$with_GL" = xyes && test "x$with_cairo" = xyes; then
  AC_MSG_ERROR([GL and cairo support cannot be enabled simultaneously.])
fi

if test "x$with_X11" = xno && test "x$with_wayland" = xno; then
  with_X11=yes
fi

if test "x$with_X11" = xyes; then
  AC_CHECK_LIB([X11], [XOpenDisplay],, AC_MSG_ERROR([Library for X11 not found.]))
fi

if test "x$with_GL" = xyes; then
  AC_CHECK_LIB([GL], [glClear],, AC_MSG_ERROR([Library for GL not found.]))
fi

if test "x$with_cairo" = xyes; then
  AC_CHECK_LIB([cairo], [cairo_version],, AC_MSG_ERROR([Library for cairo not found.]))
fi

if test "x$with_wayland" = xyes; then
  if test "x$with_GL" = xyes || test "x$with_cairo" = xyes; then
    AC_CHECK_LIB([wayland-client], [wl_display_get_fd],, AC_MSG_ERROR([Library for wayland not found.]))
  else
    AC_MSG_ERROR([wayland requires cairo or openGL to work.])
  fi
fi


AC_CONFIG_HEADERS(include/config.h)
AC_CONFIG_FILES(Makefile)

AC_OUTPUT
