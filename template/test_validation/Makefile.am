# Autoconf/automake file

bin_PROGRAMS = %%cvmhbn%_api_validate %%cvmhbn%_vxlite_validate

# General compiler/linker flags
AM_CFLAGS = -DDYNAMIC_LIBRARY -Wall -O3 -std=c99 -D_LARGEFILE_SOURCE \
        -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -I../src
AM_LDFLAGS = -L../src -l%%cvmhbn% -L../gctpc/source -lgctpc -lm -ldl

# Dist sources
%%cvmhbn%_api_validate_SOURCES = %%cvmhbn%_api_validate.c
%%cvmhbn%_vxlite_validate_SOURCES = %%cvmhbn%_vxlite_validate.c

.PHONY = run_validate run_validate_with_ucvm

all: $(bin_PROGRAMS)

############################################
# Executables
############################################

%%cvmhbn%_vxlite_validate : %%cvmhbn%_vxlite_validate.o 
	$(CC) -o $@ $^ $(AM_LDFLAGS)

%%cvmhbn%_api_validate : %%cvmhbn%_api_validate.o 
	$(CC) -o $@ $^ $(AM_LDFLAGS)

### only run after ucvm is built and installed
if UCVM

UCVM_CFLAGS = -I$(UCVM_INSTALL_PATH)/include
UCVM_LDFLAGS = -L$(UCVM_INSTALL_PATH)/lib -lucvm -dynamic  -L$(UCVM_INSTALL_PATH)/lib/euclid3/lib -letree -L$(UCVM_INSTALL_PATH)/lib/proj-5/lib -lproj -lpthread -L$(UCVM_INSTALL_PATH)/lib/fftw/lib -lfftw3 -lm -ldl

CVMH_LDFLAGS = -L$(UCVM_INSTALL_PATH)/model/cvmh/lib -lvxapi -L$(UCVM_INSTALL_PATH)/model/cvmh/lib -lgeo

CVMH_EXISTS := $(shell [[ -e $(UCVM_INSTALL_PATH)/model/cvmh/include/vx_sub.h ]] && echo 1 || echo 0 )

%%cvmhbn%_ucvm_validate.o : %%cvmhbn%_ucvm_validate.c
	$(CC) -c -o $@ $^ $(UCVM_CFLAGS) $(AM_CFLAGS) $(CFLAGS)

%%cvmhbn%_ucvm_validate : %%cvmhbn%_ucvm_validate.o 
	$(CC) -o $@ $^ $(UCVM_LDFLAGS) $(AM_LDFLAGS) $(LDFLAGS)

%%cvmhbn%_ucvm_rerun.o : %%cvmhbn%_ucvm_rerun.c
	$(CC) -c -o $@ $^ $(UCVM_CFLAGS) $(AM_CFLAGS) $(CFLAGS)

%%cvmhbn%_ucvm_rerun : %%cvmhbn%_ucvm_rerun.o 
	$(CC) -o $@ $^ $(UCVM_LDFLAGS) $(AM_LDFLAGS) $(LDFLAGS)

%%cvmhbn%_ucvm_retry.o : %%cvmhbn%_ucvm_retry.c
	$(CC) -c -o $@ $^ $(UCVM_CFLAGS) $(AM_CFLAGS) $(CFLAGS)

%%cvmhbn%_ucvm_retry : %%cvmhbn%_ucvm_retry.o 
	$(CC) -o $@ $^ $(UCVM_LDFLAGS) $(AM_LDFLAGS) $(LDFLAGS)

endif

############################################
# Special build targets
############################################

run_validate: %%cvmhbn%_api_validate %%cvmhbn%_vxlite_validate
	./run_vxlite_validate.sh
	./run_api_validate.sh

run_validate_with_ucvm: %%cvmhbn%_ucvm_validate %%cvmhbn%_ucvm_rerun %%cvmhbn%_ucvm_retry
	./run_ucvm_validate.sh

clean:
	rm -rf *~ *.o $(bin_PROGRAMS) %%cvmhbn%_ucvm_validate %%cvmhbn%_ucvm_rerun %%cvmhbn%_ucvm_retry *.txt


