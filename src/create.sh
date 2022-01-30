#!/bin/bash
num=`echo $1 | cut -d '.' -f1`
name=`echo $1 | cut -d '.' -f2`
zeroes=""
if [ "${#num}" == "1" ] 
then
    zeroes="000"
elif [ "${#num}" == "2" ]
then
    zeroes="00"
elif [ "${#num}" == "3" ]
then
   zeroes="0"
elif [ "${#num}" == "4" ]
then
   zeroes=""
fi
cppFileName=$zeroes`echo $num"_"${name// /}".cpp"`

if test -f "$cppFileName"; then
    echo "The file : $cppFileName already exists."
    exit 0
fi

echo $cppFileName" created!"

echo "//LeetCode Problem "$num" -"$name"
/*
-----------------------------------------------------------------------------------------------------------
My Method:

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include \"everything.h\"

struct Test{
};
class Solution {
    public:
        method(){
        }
        leetcode_solution(){
        }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {};
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.XXXX(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << \"Test #\" << ++count << \" : Input = \" << test.input << \", Output = \" << output << \", Time taken= \" << duration.count()/1000.0 << \" ms, Result : \" <<  (bIsPass? green : red) << (bIsPass? \"Pass\" : \"Fail\") << \"!\" << def << endl;
    }
    cout << \"Total time taken = \" << (time/1000.0) << \" ms.\" << endl;
	return 0;
}
" >> $cppFileName
