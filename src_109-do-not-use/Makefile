.SUFFIXES: .cpp $(SUFFIXES)

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
CC = g++-4.0 # OSX
else
CC = g++
endif

CFLAGS = -g -pedantic -Wall
#CFLAGS = -O3 -pedantic -Wall
DEFINES = -DUNIX

RM = rm -rf

# include rmitgp, zlib and libpng as libraries
LIB = -L../RMITGP.1.5/ -L../libpng/ -L../zlib/ -lrmitgp -lm -lpng -lz
INCLUDE = -I../RMITGP.1.5/ -I../libpng/ -I../zlib/

OBJS = main.o png.o util.o MaskMaker.o Target.o Canvas.o Decal.o \
ImageFitness.o DecalCanvas.o BezierPathCanvas.o BestCanvas.o Canny.o \
ConfigReader.o RandFloat.o ReturnFloat.o ReturnFunc.o ReturnRoot.o \
ColorConverter.o TriangleCanvas.o ShroudCanvas.o Draw2.o Draw4.o Draw6.o \
DrawColorTriangle.o DrawGrayTriangle.o Prog2.o Prog3.o Prog4.o Palette.o \
Pixel.o PaletteShroudCanvas.o

SRCS = $(OBJS:.o=.cpp)

OUTPUT = NPR-GP

$(OUTPUT): $(OBJS)
	$(CC) -o $(OUTPUT) $(OBJS) $(LIB)

.cpp.o:
	$(CC) -c $(CFLAGS) $(DEFINES) $(CXXINCLUDE) $(INCLUDE) -I. $*.cpp

backup: clean
	tar -cvf bak.tar *.cpp *.h Makefile README
	gzip -9 bak.tar

clean: reposclean
	@$(RM) $(OBJS) $(OUTPUT) *.o ../*.gz ../run-log.txt

reposclean:
	@$(RM) ../output/*.pgm
	@$(RM) ../output/*.png

objects:
	@for f in $(OBJS); do echo $(DIR)/$$f; done

depend: $(SRCS)
	@(sed <Makefile '/^#--DEPENDENCIES--$$/,$$d'; \
	echo '#--DEPENDENCIES--'; \
	$(CC) -c -M $(CFLAGS) $(CXXINCLUDE) $(INCLUDE) $(SRCS) \
	) > Makefile.new
	mv Makefile.new Makefile

#--DEPENDENCIES--
main.o: main.cpp /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc \
  /usr/include/sys/stat.h /usr/include/cygwin/stat.h \
  ../RMITGP.1.5/Population.h ../RMITGP.1.5/GeneticProgram.h \
  ../RMITGP.1.5/ReturnData.h ../RMITGP.1.5/Node.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Mutation.h ../RMITGP.1.5/Crossover.h \
  ../RMITGP.1.5/Selection.h ../RMITGP.1.5/GPConfig.h \
  ../RMITGP.1.5/Random.h ../RMITGP.1.5/Fitness.h ../RMITGP.1.5/NodeSet.h \
  ../RMITGP.1.5/Function.h ../RMITGP.1.5/Terminal.h \
  ../RMITGP.1.5/Fitness.h ../RMITGP.1.5/TournamentSelection.h \
  ../RMITGP.1.5/GeneticProgram.h ../RMITGP.1.5/NodeSet.h \
  ../RMITGP.1.5/ProgramGenerator.h ../RMITGP.1.5/NodeVector.h \
  ../RMITGP.1.5/GPConfig.h Prog2.h ../RMITGP.1.5/Function.h ReturnFunc.h \
  ../RMITGP.1.5/ReturnData.h Prog3.h ReturnRoot.h Prog4.h Draw2.h \
  ReturnFloat.h Canvas.h Utility.h png.h util.h Target.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h Draw4.h Draw6.h \
  BezierPathCanvas.h Decal.h Palette.h Pixel.h RandFloat.h \
  ../RMITGP.1.5/Terminal.h ImageFitness.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/float.h /usr/include/errno.h \
  /usr/include/sys/errno.h DecalCanvas.h ShroudCanvas.h \
  PaletteShroudCanvas.h TriangleCanvas.h MaskMaker.h DrawColorTriangle.h \
  DrawGrayTriangle.h
png.o: png.cpp /usr/include/stdio.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/sys/features.h \
  /usr/include/cygwin/config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/types.h \
  /usr/include/machine/types.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/endian.h /usr/include/byteswap.h /usr/include/sys/stdio.h \
  /usr/include/sys/cdefs.h /usr/include/stdlib.h \
  /usr/include/machine/stdlib.h /usr/include/alloca.h \
  /usr/include/cygwin/stdlib.h /usr/include/cygwin/wait.h ../libpng/png.h \
  ../zlib/zlib.h ../zlib/zconf.h ../libpng/pngconf.h \
  /usr/include/setjmp.h /usr/include/machine/setjmp.h \
  /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/string.h \
  /usr/include/sys/string.h /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  ../libpng/pngconf.h png.h util.h
util.o: util.cpp /usr/include/stdio.h /usr/include/_ansi.h \
  /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/sys/features.h \
  /usr/include/cygwin/config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/types.h \
  /usr/include/machine/types.h /usr/include/cygwin/types.h \
  /usr/include/sys/sysmacros.h /usr/include/stdint.h \
  /usr/include/endian.h /usr/include/byteswap.h /usr/include/sys/stdio.h \
  /usr/include/sys/cdefs.h /usr/include/stdlib.h \
  /usr/include/machine/stdlib.h /usr/include/alloca.h \
  /usr/include/cygwin/stdlib.h /usr/include/cygwin/wait.h util.h \
  /usr/include/errno.h /usr/include/sys/errno.h /usr/include/string.h \
  /usr/include/sys/string.h
MaskMaker.o: MaskMaker.cpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h MaskMaker.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h Utility.h png.h util.h
Target.o: Target.cpp Target.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/sys/reent.h /usr/include/_ansi.h \
  /usr/include/sys/_types.h /usr/include/machine/_types.h \
  /usr/include/machine/_default_types.h /usr/include/sys/lock.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  Utility.h png.h util.h ColorConverter.h Canny.h
Canvas.o: Canvas.cpp Canvas.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/sys/reent.h /usr/include/_ansi.h \
  /usr/include/sys/_types.h /usr/include/machine/_types.h \
  /usr/include/machine/_default_types.h /usr/include/sys/lock.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc Utility.h \
  png.h util.h Target.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc
Decal.o: Decal.cpp Decal.h /usr/include/math.h /usr/include/sys/reent.h \
  /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/machine/ieeefp.h /usr/include/sys/features.h \
  /usr/include/cygwin/config.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h /usr/include/_ansi.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  Utility.h ColorConverter.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc
ImageFitness.o: ImageFitness.cpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h ImageFitness.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/float.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/include/errno.h /usr/include/sys/errno.h \
  ../RMITGP.1.5/GeneticProgram.h ../RMITGP.1.5/ReturnData.h \
  ../RMITGP.1.5/Node.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Population.h ../RMITGP.1.5/GeneticProgram.h \
  ../RMITGP.1.5/Mutation.h ../RMITGP.1.5/Crossover.h \
  ../RMITGP.1.5/Selection.h ../RMITGP.1.5/GPConfig.h \
  ../RMITGP.1.5/Random.h ../RMITGP.1.5/Fitness.h ../RMITGP.1.5/NodeSet.h \
  ../RMITGP.1.5/Function.h ../RMITGP.1.5/Terminal.h \
  ../RMITGP.1.5/Fitness.h ../RMITGP.1.5/GPConfig.h DecalCanvas.h Canvas.h \
  Utility.h png.h util.h Target.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc Decal.h \
  Palette.h Pixel.h BezierPathCanvas.h ShroudCanvas.h ReturnFloat.h \
  ../RMITGP.1.5/ReturnData.h ReturnFunc.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iomanip \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/functional
DecalCanvas.o: DecalCanvas.cpp DecalCanvas.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/sys/reent.h /usr/include/_ansi.h \
  /usr/include/sys/_types.h /usr/include/machine/_types.h \
  /usr/include/machine/_default_types.h /usr/include/sys/lock.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc Canvas.h \
  /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc Utility.h \
  png.h util.h Target.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc Decal.h \
  Palette.h Pixel.h
BezierPathCanvas.o: BezierPathCanvas.cpp BezierPathCanvas.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/sys/reent.h /usr/include/_ansi.h \
  /usr/include/sys/_types.h /usr/include/machine/_types.h \
  /usr/include/machine/_default_types.h /usr/include/sys/lock.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc Canvas.h \
  /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc Utility.h \
  png.h util.h Target.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc Decal.h \
  Palette.h Pixel.h
BestCanvas.o: BestCanvas.cpp BestCanvas.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/sys/reent.h /usr/include/_ansi.h \
  /usr/include/sys/_types.h /usr/include/machine/_types.h \
  /usr/include/machine/_default_types.h /usr/include/sys/lock.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h Utility.h png.h util.h Target.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h
Canny.o: Canny.cpp Canny.h Utility.h png.h util.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/sys/reent.h /usr/include/_ansi.h \
  /usr/include/sys/_types.h /usr/include/machine/_types.h \
  /usr/include/machine/_default_types.h /usr/include/sys/lock.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h
ConfigReader.o: ConfigReader.cpp ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream
RandFloat.o: RandFloat.cpp RandFloat.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  ../RMITGP.1.5/Terminal.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Node.h ../RMITGP.1.5/ReturnData.h \
  ../RMITGP.1.5/GPConfig.h ../RMITGP.1.5/Random.h \
  ../RMITGP.1.5/Crossover.h ../RMITGP.1.5/GeneticProgram.h \
  ../RMITGP.1.5/Mutation.h ../RMITGP.1.5/Selection.h \
  ../RMITGP.1.5/Fitness.h ../RMITGP.1.5/NodeSet.h \
  ../RMITGP.1.5/Function.h ../RMITGP.1.5/Terminal.h ReturnFloat.h \
  ../RMITGP.1.5/ReturnData.h
ReturnFloat.o: ReturnFloat.cpp ReturnFloat.h ../RMITGP.1.5/ReturnData.h
ReturnFunc.o: ReturnFunc.cpp ReturnFunc.h ../RMITGP.1.5/ReturnData.h
ReturnRoot.o: ReturnRoot.cpp ReturnRoot.h ../RMITGP.1.5/ReturnData.h
ColorConverter.o: ColorConverter.cpp ColorConverter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  Utility.h
TriangleCanvas.o: TriangleCanvas.cpp \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h /usr/include/math.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  TriangleCanvas.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc Canvas.h \
  Utility.h png.h util.h Target.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc Pixel.h
ShroudCanvas.o: ShroudCanvas.cpp /usr/include/math.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/_types.h /usr/include/machine/_types.h \
  /usr/include/machine/_default_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h /usr/include/_ansi.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ShroudCanvas.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc Canvas.h \
  Utility.h png.h util.h Target.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc Pixel.h
Draw2.o: Draw2.cpp Draw2.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h ../RMITGP.1.5/Function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Node.h ../RMITGP.1.5/ReturnData.h ReturnFunc.h \
  ../RMITGP.1.5/ReturnData.h ReturnFloat.h Canvas.h Utility.h png.h \
  util.h Target.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc
Draw4.o: Draw4.cpp Draw4.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h ../RMITGP.1.5/Function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Node.h ../RMITGP.1.5/ReturnData.h ReturnFunc.h \
  ../RMITGP.1.5/ReturnData.h ReturnFloat.h Canvas.h Utility.h png.h \
  util.h Target.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc
Draw6.o: Draw6.cpp Draw6.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h ../RMITGP.1.5/Function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Node.h ../RMITGP.1.5/ReturnData.h ReturnFunc.h \
  ../RMITGP.1.5/ReturnData.h ReturnFloat.h BezierPathCanvas.h Canvas.h \
  Utility.h png.h util.h Target.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc Decal.h \
  Palette.h Pixel.h
DrawColorTriangle.o: DrawColorTriangle.cpp DrawColorTriangle.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h ../RMITGP.1.5/Function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Node.h ../RMITGP.1.5/ReturnData.h ReturnFunc.h \
  ../RMITGP.1.5/ReturnData.h ReturnFloat.h BezierPathCanvas.h Canvas.h \
  Utility.h png.h util.h Target.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc Decal.h \
  Palette.h Pixel.h
DrawGrayTriangle.o: DrawGrayTriangle.cpp DrawGrayTriangle.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h ../RMITGP.1.5/Function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Node.h ../RMITGP.1.5/ReturnData.h ReturnFunc.h \
  ../RMITGP.1.5/ReturnData.h ReturnFloat.h BezierPathCanvas.h Canvas.h \
  Utility.h png.h util.h Target.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc Decal.h \
  Palette.h Pixel.h
Prog2.o: Prog2.cpp Prog2.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/include/math.h ../RMITGP.1.5/Function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Node.h ../RMITGP.1.5/ReturnData.h ReturnFunc.h \
  ../RMITGP.1.5/ReturnData.h ../RMITGP.1.5/GPConfig.h \
  ../RMITGP.1.5/Random.h ../RMITGP.1.5/Crossover.h \
  ../RMITGP.1.5/GeneticProgram.h ../RMITGP.1.5/Mutation.h \
  ../RMITGP.1.5/Selection.h ../RMITGP.1.5/Fitness.h \
  ../RMITGP.1.5/NodeSet.h ../RMITGP.1.5/Function.h \
  ../RMITGP.1.5/Terminal.h
Prog3.o: Prog3.cpp Prog3.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  ../RMITGP.1.5/Function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Node.h ../RMITGP.1.5/ReturnData.h ReturnFunc.h \
  ../RMITGP.1.5/ReturnData.h ReturnRoot.h ../RMITGP.1.5/GPConfig.h \
  ../RMITGP.1.5/Random.h ../RMITGP.1.5/Crossover.h \
  ../RMITGP.1.5/GeneticProgram.h ../RMITGP.1.5/Mutation.h \
  ../RMITGP.1.5/Selection.h ../RMITGP.1.5/Fitness.h \
  ../RMITGP.1.5/NodeSet.h ../RMITGP.1.5/Function.h \
  ../RMITGP.1.5/Terminal.h
Prog4.o: Prog4.cpp Prog4.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  ../RMITGP.1.5/Function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  ../RMITGP.1.5/Node.h ../RMITGP.1.5/ReturnData.h ReturnFunc.h \
  ../RMITGP.1.5/ReturnData.h ReturnRoot.h ../RMITGP.1.5/GPConfig.h \
  ../RMITGP.1.5/Random.h ../RMITGP.1.5/Crossover.h \
  ../RMITGP.1.5/GeneticProgram.h ../RMITGP.1.5/Mutation.h \
  ../RMITGP.1.5/Selection.h ../RMITGP.1.5/Fitness.h \
  ../RMITGP.1.5/NodeSet.h ../RMITGP.1.5/Function.h \
  ../RMITGP.1.5/Terminal.h
Palette.o: Palette.cpp Palette.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/stdlib.h /usr/include/machine/ieeefp.h \
  /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/sys/_types.h \
  /usr/include/machine/_types.h /usr/include/machine/_default_types.h \
  /usr/include/sys/lock.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/include/string.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream Utility.h \
  Target.h /usr/include/math.h png.h util.h ColorConverter.h Canny.h \
  Pixel.h
Pixel.o: Pixel.cpp Pixel.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h \
  /usr/include/string.h /usr/include/sys/reent.h /usr/include/_ansi.h \
  /usr/include/sys/_types.h /usr/include/machine/_types.h \
  /usr/include/machine/_default_types.h /usr/include/sys/lock.h \
  /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc Utility.h \
  ColorConverter.h /usr/include/math.h
PaletteShroudCanvas.o: PaletteShroudCanvas.cpp /usr/include/math.h \
  /usr/include/sys/reent.h /usr/include/_ansi.h /usr/include/newlib.h \
  /usr/include/sys/config.h /usr/include/machine/ieeefp.h \
  /usr/include/sys/features.h /usr/include/cygwin/config.h \
  /usr/include/sys/_types.h /usr/include/machine/_types.h \
  /usr/include/machine/_default_types.h /usr/include/sys/lock.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stddef.h /usr/include/_ansi.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/vector \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/functexcept.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algobase.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++config.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/os_defines.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstring \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstddef \
  /usr/include/string.h /usr/include/sys/string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/climits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/limits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/syslimits.h \
  /usr/include/limits.h /usr/include/features.h /usr/include/sys/cdefs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdlib \
  /usr/include/stdlib.h /usr/include/machine/stdlib.h \
  /usr/include/alloca.h /usr/include/cygwin/stdlib.h \
  /usr/include/cygwin/wait.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/new \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/exception \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iosfwd \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/clocale \
  /usr/include/locale.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cstdio \
  /usr/include/stdio.h /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/stdarg.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/cygwin/types.h /usr/include/sys/sysmacros.h \
  /usr/include/stdint.h /usr/include/endian.h /usr/include/byteswap.h \
  /usr/include/sys/stdio.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++io.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/gthr-default.h \
  /usr/include/pthread.h /usr/include/signal.h /usr/include/sys/signal.h \
  /usr/include/cygwin/signal.h /usr/include/sched.h \
  /usr/include/sys/sched.h /usr/include/unistd.h \
  /usr/include/sys/unistd.h /usr/include/getopt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cctype \
  /usr/include/ctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stringfwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/postypes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwchar \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ctime /usr/include/time.h \
  /usr/include/machine/time.h /usr/include/cygwin/time.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_pair.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_types.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator_base_funcs.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/concept_check.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/debug/debug.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cassert \
  /usr/include/assert.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/c++allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ext/new_allocator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_construct.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_uninitialized.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_vector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_bvector.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/vector.tcc \
  PaletteShroudCanvas.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ostream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/ios \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/char_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/localefwd.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ios_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/atomicity.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/atomic_word.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_classes.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/string \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/memory \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_raw_storage_iter.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/limits \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_function.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/algorithm \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_algo.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_heap.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tempbuf.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_string.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/streambuf \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/streambuf_iterator.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/cwctype \
  /usr/include/wctype.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_base.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/ctype_inline.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/codecvt.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/time_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/messages_members.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/basic_ios.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/ostream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/locale \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/locale_facets.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/typeinfo \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/istream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/istream.tcc Canvas.h \
  Utility.h png.h util.h Target.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/set \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_tree.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/cpp_type_traits.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_set.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/stl_multiset.h \
  ColorConverter.h Canny.h BestCanvas.h ConfigReader.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/fstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/i686-pc-cygwin/bits/basic_file.h \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/fstream.tcc \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/sstream \
  /usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/bits/sstream.tcc Pixel.h \
  Palette.h
