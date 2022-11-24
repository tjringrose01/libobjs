AC_INIT(libobjs,1.0)
 
AM_INIT_AUTOMAKE
 
AM_CONFIG_HEADER([src/config.h])
 
CFLAGS=" $CFLAGS -g"
 
CXXFLAGS=" $CXXFLAGS -g -DDEBUG"
 
LDFLAGS=" $LDFLAGS -g"
 
# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_AWK
AC_PROG_RANLIB
 
# Checks for header files.
AC_HEADER_STDC
 
AC_CHECK_HEADERS([arpa/inet.h fcntl.h limits.h malloc.h netdb.h \
netinet/in.h stddef.h stdlib.h string.h sys/ioctl.h sys/socket.h sys/time.h unistd.h])
 
# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_CHECK_TYPES([ptrdiff_t])
 
# Checks for library functions.
AC_PROG_GCC_TRADITIONAL
AC_FUNC_MEMCMP
AC_CHECK_FUNCS([gethostbyname gettimeofday memmove memset pow select socket])
 
AC_PATH_PROG(libobjs)
AC_OUTPUT([Makefile src/Makefile])
 
echo
echo $PACKAGE $VERSION
echo
eval eval echo libobjs will be installed in $bindir.
if test "x$libobjs" != "x" ; then
	echo Warning: You have an old copy of libobjs at $libobjs.
fi
echo
echo configure complete, now type 'make' and then 'make install'
echo
