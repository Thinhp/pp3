# Originally  makefile for libpng using gcc (generic, static library)
# Copyright (C) 2000 Cosmin Truta
# Copyright (C) 1995 Guy Eric Schalnat, Group 42, Inc.
# For conditions of distribution and use, see copyright notice in png.h
#
# Adapted for makefile for zlib using gcc (generic, static library)

# Compiler, linker, lib and other tools
CC = gcc
LD = $(CC)
AR_RC = ar rcs
RANLIB = ranlib
RM_F = rm -f

CDEBUG = -g -DPNG_DEBUG=5
LDDEBUG =
CRELEASE = -O2
LDRELEASE = -s
#CFLAGS = -Wall $(CDEBUG)
CFLAGS = -Wall $(CRELEASE)
#LDFLAGS = $(LDDEBUG)
LDFLAGS = $(LDRELEASE)
LIBS = -lm

# File extensions
O=.o
A=.a
EXE=

# Variables
OBJS = adler32$(O) compress$(O) crc32$(O) deflate$(O) \
       gzio$(O) infback$(O) inffast$(O) inflate$(O) \
       inftrees$(O) trees$(O) uncompr$(O) zutil$(O)

# Targets
all: static

.c$(O):
	$(CC) -c $(CFLAGS) $<

static: libzlib$(A)

libzlib$(A): $(OBJS)
	$(AR_RC) $@ $(OBJS)
	$(RANLIB) $@

clean:
	$(RM_F) *$(O) libzlib$(A)

adler32$(O): zlib.h zconf.h
compress$(O): zlib.h zconf.h
crc32$(O): zutil.h zlib.h zconf.h crc32.h
deflate$(O): deflate.h zutil.h zlib.h zconf.h
gzio$(O): zutil.h zlib.h zconf.h
infback$(O): zutil.h zlib.h zconf.h inftrees.h inflate.h inffast.h inffixed.h
inffast$(O): zutil.h zlib.h zconf.h inftrees.h inflate.h inffast.h 
inflate$(O): zutil.h zlib.h zconf.h inftrees.h inflate.h inffast.h inffixed.h
inftrees$(O): zutil.h zlib.h zconf.h inftrees.h
trees$(O): deflate.h zutil.h zlib.h zconf.h trees.h
uncompr$(O): zlib.h zconf.h
zutil$(O): zutil.h zlib.h zconf.h

