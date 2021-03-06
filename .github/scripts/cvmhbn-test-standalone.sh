#!/bin/bash

## testing the cvmh basin part only

if [ -d ../$1  ]; then 
  cd ../$1
fi

cd test

make run_unit | tee result_unit.txt

p=`grep -c FAIL result_unit.txt` 
if [ $p != 0 ]; then
   echo "something wrong.."
   exit 1 
fi

make run_accept | tee result_accept.txt

p=`grep -c FAIL result_accept.txt` 
if [ $p != 0 ]; then
   echo "something wrong.."
   exit 1 
fi

echo "okay"
exit 0
