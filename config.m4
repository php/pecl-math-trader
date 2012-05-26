dnl $Id$
dnl config.m4 for extension ta

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(ta, for ta support,
dnl Make sure that the comment is aligned:
dnl [  --with-ta             Include ta support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(ta, whether to enable ta support,
dnl Make sure that the comment is aligned:
dnl [  --enable-ta           Enable ta support])

if test "$PHP_TA" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-ta -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/ta.h"  # you most likely want to change this
  dnl if test -r $PHP_TA/$SEARCH_FOR; then # path given as parameter
  dnl   TA_DIR=$PHP_TA
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for ta files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       TA_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$TA_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the ta distribution])
  dnl fi

  dnl # --with-ta -> add include path
  dnl PHP_ADD_INCLUDE($TA_DIR/include)

  dnl # --with-ta -> check for lib and symbol presence
  dnl LIBNAME=ta # you may want to change this
  dnl LIBSYMBOL=ta # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $TA_DIR/lib, TA_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_TALIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong ta lib version or lib not found])
  dnl ],[
  dnl   -L$TA_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(TA_SHARED_LIBADD)

  PHP_NEW_EXTENSION(ta, ta.c, $ext_shared)
fi
