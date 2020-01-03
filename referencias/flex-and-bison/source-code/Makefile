# $Header: /home/johnl/flnb/code/RCS/Makefile,v 2.1 2009/11/08 02:53:18 johnl Exp $
# Companion source code for "flex & bison", published by O'Reilly
# Media, ISBN 978-0-596-15597-1
# Copyright (c) 2009, Taughannock Networks. All rights reserved.
# See the README file for license conditions and contact info.

# Make all the examples

SOURCES=README \
	chap-1/fb1-1.l \
	chap-1/fb1-2.l \
	chap-1/fb1-3.l \
	chap-1/fb1-4.l \
	chap-1/fb1-5.l \
	chap-1/fb1-5.y \
	chap-2/fb2-1.l \
	chap-2/fb2-2.l \
	chap-2/fb2-3.l \
	chap-2/fb2-4.l \
	chap-2/fb2-5.l \
	chap-3/fb3-1.l \
	chap-3/fb3-1.y \
	chap-3/fb3-1.h \
	chap-3/fb3-1funcs.c \
	chap-3/fb3-2.l \
	chap-3/fb3-2.y \
	chap-3/fb3-2.h \
	chap-3/fb3-2funcs.c \
	purewc.l \
	purecalc.h \
	purecalc.l \
	purecalc.y \
	purecalcfuncs.c \
	cppcalc.l \
	cppcalc.yy \
	cppcalc-ctx.hh \
	Makefile \
	chap-1/Makefile.ch1 \
	chap-2/Makefile.ch2 \
	chap-3/Makefile.ch3 \
	chap-9/Makefile.ch9 \
	${SQLFILES}

SQLFILES=sql/Makefile \
	sql/glrmysql.y \
	sql/lpmysql.y \
	sql/pmysql.y \
	sql/glrmysql.l \
	sql/lpmysql.l \
	sql/pmysql.l

All:
	$(MAKE) -f chap-1/Makefile.ch1
	$(MAKE) -f chap-2/Makefile.ch2
	$(MAKE) -f chap-3/Makefile.ch3
	$(MAKE) -f chap-9/Makefile.ch9
	cd sql; $(MAKE)

clean:
	$(MAKE) -f chap-1/Makefile.ch1 clean
	$(MAKE) -f chap-2/Makefile.ch2 clean
	$(MAKE) -f chap-3/Makefile.ch3 clean
	$(MAKE) -f chap-9/Makefile.ch9 clean
	cd sql; $(MAKE) clean

zip::	flexbison.zip

flexbison.zip:	${SOURCES}
	rm -f $@
	zip -FS $@ ${SOURCES}
