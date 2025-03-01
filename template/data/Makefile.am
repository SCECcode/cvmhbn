# Autoconf/automake file

# General compiler/linker flags
AM_CFLAGS = ${CFLAGS}
AM_FCFLAGS = ${FCFLAGS}
AM_LDFLAGS = ${LDFLAGS}

all:
if WITH_CVMH_LARGEDATA_DIR
	echo "USING WITH_CVMH_LARGEDATA_DIR in %%cvmhbn%"
else
	./make_data_files.py
endif

install:
if WITH_CVMH_LARGEDATA_DIR
	if [ ! -d "${prefix}/data/%%cvmhbn%" ]; then \
		$(MKDIR_P) ${prefix}/data; \
		$(LN_S) -f $(CVMH_LARGEDATA_DIR) ${prefix}/data/%%cvmhbn%; \
		echo "USING WITH_CVMH_LARGEDATA_DIR in %%cvmhbn%"; \
	fi
	cp config ${prefix}/data
else
	if [ ! -d "${prefix}/data/%%cvmhbn%" ]; then \
		$(MKDIR_P) ${prefix}/data; \
		mv %%cvmhbn% ${prefix}/data; \
		$(LN_S) -f ${prefix}/data/%%cvmhbn% .; \
	fi
	cp config ${prefix}/data
endif

dist-clean :
	echo "clean"
