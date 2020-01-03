# $Header: /home/johnl/flnb/code/RCS/Makefile.ch3,v 2.1 2009/11/08 02:53:18 johnl Exp $
# Companion source code for "flex & bison", published by O'Reilly
# Media, ISBN 978-0-596-15597-1
# Copyright (c) 2009, Taughannock Networks. All rights reserved.
# See the README file for license conditions and contact info.

# programs in chapter 3

STD89=-std=c89

run:	clean all
	./fb3-2
	
all:	fb3-2

fb3-2:	fb3-2.l fb3-2.y fb3-2.h fb3-2funcs.c
	bison -d $@.y 
	flex -o $@.lex.c $@.l 
	cc -g -o $@ $@.tab.c $@.lex.c $@funcs.c -lm ${STD89} 

clean:
	rm -rf fb3-2 fb3-2.lex.c fb3-2.tab.h fb3-2.tab.c fb3-2.dSYM
