#!/bin/bash
cppFilePath=$1
filename=`echo $cppFilePath | cut -d '/' -f2 | cut -d '.' -f1`
echo "C++ File = "$filename
echo "gcc "${cppFilePath}" -lstdc++ -o ../build/"$filename
gcc $cppFilePath -lstdc++ -o "../build/"${filename}
../build/${filename}
