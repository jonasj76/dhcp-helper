CLEANFILES = *.trs *.log

if HAVE_CHECK

TESTS      = check_config
AM_CFLAGS  = -I$(top_srcdir)/src @CHECK_CFLAGS@
AM_LDFLAGS = -L$(top_srcdir)/src
LIBS       = -ljansson
LDADD      = @CHECK_LIBS@

check_config_SOURCES = check_config.c ../src/conf.c ../src/logging.c

check_PROGRAMS = $(TESTS)

endif
