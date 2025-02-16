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
            [if test x$withval = xyes; then
              with_X11 = yes
              with_wayland = no
              with_ncurses = no
            else
              with_X11 = no
            fi], [with_X11=yes])
AC_ARG_WITH([wayland], [  --with-wayland],
            [if test x$withval = xyes; then
              with_wayland = yes
              with_X11 = no
              with_ncurses = no
            else
              with_wayland = no
            fi], [with_wayland=no])
AC_ARG_WITH([ncurses],  [  --with-ncurses],
            [if test x$withval = xyes; then
              with_ncurses = yes
              with_X11 = no
              with_wayland = no
            else
              with_ncurses = no
            fi], [with_ncurses=no])

if test "x$with_X11" = xyes && test "x$with_wayland" = xyes; then
  AC_MSG_ERROR([X11 and Wayland support cannot be enabled simultaneously.])
fi
if test "x$with_X11" = xyes && test "x$with_ncurses" = xyes; then
  AC_MSG_ERROR([X11 and Ncurses support cannot be enabled simultaneously.])
fi
if test "x$with_wayland" = xyes && test "x$with_ncurses" = xyes; then
  AC_MSG_ERROR([Wayland and Ncurses support cannot be enabled simultaneously.])
fi

# Default to X11 if no option is specified
if test "x$with_X11" = xno && test "x$with_wayland" = xno && test "x$with_ncurses" = xno; then
  with_X11=yes
fi

AC_CONFIG_HEADERS(include/config.h)
AC_CONFIG_FILES(Makefile)

AC_OUTPUT
