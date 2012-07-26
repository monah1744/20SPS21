## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src po

hq_for_juledocdir = ${prefix}/doc/hq_for_jule
hq_for_juledoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = $(hq_for_juledoc_DATA) \
	$(INTLTOOL_FILES)

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(hq_for_juledocdir)
