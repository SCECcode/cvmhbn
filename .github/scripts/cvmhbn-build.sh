#!/bin/bash

tmp=`uname -s`

if [ $tmp == 'Darwin' ]; then
##for macOS, make sure have automake/aclocal
  brew install automake
fi

cvmhbn/setup.sh $1
cd $1
pwd
ls
aclocal
automake --add-missing
autoconf
cd data
./make_data_files.py
cd ..
./configure --prefix=$UCVM_INSTALL_PATH/model/$1
make
make install

