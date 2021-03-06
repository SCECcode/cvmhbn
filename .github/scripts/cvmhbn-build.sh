#!/bin/bash

tmp=`uname -s`

if [ $tmp == 'Darwin' ]; then
##for macOS, make sure have automake/aclocal
  brew install automake
fi

## check if at the right location
if [ -d ../$1  ]; then 
  cd ../$1
fi

aclocal
automake --add-missing
autoconf
cd data
./make_data_files.py
cd ..
./configure --prefix=$UCVM_INSTALL_PATH/model/$1
make
make install

