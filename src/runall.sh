#!/bin/bash
for cpp in `ls | grep -i '.cpp'`
do
    echo "Running "$cpp
    ./make.sh $cpp
    echo ""
done
