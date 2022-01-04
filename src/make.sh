#!/bin/bash
cppFilePath=$1
filename=`echo $cppFilePath | cut -d '/' -f2 | cut -d '.' -f1`
echo "Source = \""$filename".cpp\""
echo "gcc "${cppFilePath}" -lstdc++ -o ../build/"$filename
gcc $cppFilePath -lstdc++ -o "../build/"${filename}
#gcc $cppFilePath -std=c++11 -o "../build/"${filename}
../build/${filename}
