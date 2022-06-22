#!/bin/bash

## only with a cvmhbn (git@github.com:SCECcode/cvmhbn.git)
cwd=`pwd`
CVMHBN=${cwd}/cvmhbn

if [ ! -d ${CVMHBN}  ]; then 
  echo "need to git clone cvmhbn in current directory first!!!"
  exit 1 
fi

if [ $# -ne 1 ]; then
        printf "Usage: %s: [options] <basin_name>\n" $(basename $0) >&2    
        exit 1
fi

## basin name ie. cvmhsgbn
BN=$1
BN_SED=${BN}_sed_cmd

## should have a sed_command file
if [ ! -f ${CVMHBN}/setup/sed_command/${BN_SED} ]; then
        printf "%s is needed!!\n" ${CVMHBN}/setup/sed_command/${BN_SED}
        exit 1
fi

TARGET=${cwd}/${BN}


cp -R ${CVMHBN}/top ${TARGET} 

## setup top
cd ${TARGET}
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/CITATION.cff > CITATION.cff
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/configure.ac > configure.ac
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/Doxyfile > Doxyfile
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/README.md > README.md

## setup data
mkdir -p ${TARGET}/data
cd ${TARGET}/data
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/data/Makefile.am > Makefile.am
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/data/config > config
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/data/make_data_files.py > make_data_files.py
chmod +x make_data_files.py

## setup src
cd ${TARGET}/src
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/src/Makefile.am > Makefile.am
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/src/run_vx_cvmhbn.sh > run_vx_${BN}.sh
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/src/run_vx_lite_cvmhbn.sh > run_vx_lite_${BN}.sh
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/src/run_vx_cvmhbn.sh > run_vx_${BN}.sh
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/src/cvmhbn.h > ${BN}.h
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/src/cvmhbn.c > ${BN}.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/src/vx_lite_cvmhbn.c > vx_lite_${BN}.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/src/vx_cvmhbn.c > vx_${BN}.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/src/vx_sub_cvmhbn.c > vx_sub_${BN}.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/src/vx_sub_cvmhbn.h > vx_sub_${BN}.h
chmod +x run*.sh

## setup test
cd ${TARGET}/test
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/Makefile.am > Makefile.am
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/test_cvmhbn_exec.c > test_${BN}_exec.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/test_cvmhbn_exec.h > test_${BN}_exec.h
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/test_vx_cvmhbn_exec.c > test_vx_${BN}_exec.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/test_vx_cvmhbn_exec.h > test_vx_${BN}_exec.h
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/test_vx_lite_cvmhbn_exec.c > test_vx_lite_${BN}_exec.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/test_vx_lite_cvmhbn_exec.h > test_vx_lite_${BN}_exec.h
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/test_helper.c > test_helper.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/test_helper.h > test_helper.h
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/test_grid_exec.c > test_grid_exec.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/unittest.c > unittest.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test/unittest_defs.h > unittest_defs.h

cd ${TARGET}/test/inputs
cp ${CVMHBN}/template/test/inputs/${BN}/* .

cd ${TARGET}/test/ref
cp ${CVMHBN}/template/test/ref/${BN}/* .

## setup test_validation
mkdir -p ${TARGET}/test_validation
cd ${TARGET}/test_validation
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test_validation/Makefile.am > Makefile.am
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test_validation/run_api_validate.sh > run_api_validate.sh
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test_validation/run_ucvm_validate.sh > run_ucvm_validate.sh
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test_validation/run_vxlite_validate.sh > run_vxlite_validate.sh
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test_validation/cvmhbn_vxlite_validate.c > ${BN}_vxlite_validate.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test_validation/cvmhbn_api_validate.c > ${BN}_api_validate.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test_validation/cvmhbn_ucvm_validate.c > ${BN}_ucvm_validate.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test_validation/cvmhbn_ucvm_rerun.c > ${BN}_ucvm_rerun.c
sed -f ${CVMHBN}/setup/sed_command/${BN_SED} ${CVMHBN}/template/test_validation/cvmhbn_ucvm_retry.c > ${BN}_ucvm_retry.c
chmod +x run*.sh
