#!/bin/bash
##
## validate with %%cvmhbn% vxlite api
## 
rm -rf validate_vxlite_bad.txt 
rm -rf validate_vxlite_good.txt

if [ ! -f ../data/%%cvmhbn%/%%CVMHBN_DAT% ]; then 
  echo "need to retrieve %%CVMHBN_DAT% first!!!"
  exit 1
fi

if [ "x$UCVM_INSTALL_PATH" != "x" ] ; then
  if [ -f $SCRIPT_DIR/../conf/ucvm_env.sh  ] ; then
    SCRIPT_DIR="$UCVM_INSTALL_PATH"/bin
    source $SCRIPT_DIR/../conf/ucvm_env.sh
    ./%%cvmhbn%_vxlite_validate -m ../data/%%cvmhbn% -f ../data/%%cvmhbn%/%%CVMHBN_DAT%
    exit
  fi
fi

SCRIPT_DIR="$( cd "$( dirname "$0" )" && pwd )"
env DYLD_LIBRARY_PATH=${SCRIPT_DIR}/../src LD_LIBRARY_PATH=${SCRIPT_DIR}/../src ./%%cvmhbn%_vxlite_validate -m ../data/%%cvmhbn% -f ../data/%%cvmhbn%/%%CVMHBN_DAT%
