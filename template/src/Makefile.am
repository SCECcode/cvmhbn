# Autoconf/automake file

lib_LIBRARIES = libvxapi_%%cvmhbn%.a lib%%cvmhbn%.a 
bin_PROGRAMS = vx_lite_%%cvmhbn% vx_%%cvmhbn%
include_HEADERS = vx_sub_%%cvmhbn%.h %%cvmhbn%.h
 
# General compiler/linker flags
AM_CFLAGS = -Wall -O3 -std=c99 -D_LARGEFILE_SOURCE \
            -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -fPIC
AM_LDFLAGS = -L../gctpc/source -lgctpc -lm

# Dist sources
lib%%cvmhbn%_a_SOURCES = vx_sub_%%cvmhbn%.c vx_io.c 
vx_lite_%%cvmhbn%_SOURCES = vx_lite_%%cvmhbn%.c
vx_%%cvmhbn%_SOURCES = %%cvmhbn%.c vx_%%cvmhbn%.c

TARGETS = vx_lite_%%cvmhbn% vx_%%cvmhbn% libvxapi_%%cvmhbn%.a lib%%cvmhbn%.a lib%%cvmhbn%.so

all: $(TARGETS)

install:
	mkdir -p ${prefix}
	mkdir -p ${prefix}/lib
	mkdir -p ${prefix}/include
	cp lib%%cvmhbn%.so ${prefix}/lib
	cp lib%%cvmhbn%.a ${prefix}/lib
	cp %%cvmhbn%.h ${prefix}/include

lib%%cvmhbn%.a: vx_sub_%%cvmhbn%.o vx_io.o utils.o %%cvmhbn%_static.o 
	$(AR) rcs $@ $^

%%cvmhbn%_static.o: %%cvmhbn%.c
	$(CC) -o $@ -c $^ $(AM_CFLAGS)

lib%%cvmhbn%.so: vx_sub_%%cvmhbn%.o vx_io.o utils.o %%cvmhbn%.o
	$(CC) -shared $(AM_CFLAGS) -o lib%%cvmhbn%.so $^ $(AM_LDFLAGS)

libvxapi_%%cvmhbn%.a: vx_sub_%%cvmhbn%.o vx_io.o utils.o 
	$(AR) rcs $@ $^

%%cvmhbn%.o: %%cvmhbn%.c
	$(CC) -fPIC -DDYNAMIC_LIBRARY -o $@ -c $^ $(AM_CFLAGS)

vx_lite_%%cvmhbn%.o : vx_lite_%%cvmhbn%.c
	$(CC) -o $@ -c $^ $(AM_CFLAGS)

vx_lite_%%cvmhbn% : vx_lite_%%cvmhbn%.o libvxapi_%%cvmhbn%.a
	$(CC) -o $@ $^ $(AM_LDFLAGS)

vx_%%cvmhbn%.o : vx_%%cvmhbn%.c
	$(CC) -o $@ -c $^ $(AM_CFLAGS)

vx_%%cvmhbn% : vx_%%cvmhbn%.o lib%%cvmhbn%.a
	$(CC) -o $@ $^ $(AM_LDFLAGS)

clean:
	rm -rf $(TARGETS)
	rm -rf *.o 

