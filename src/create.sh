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
    int count = 0;
    for(auto test: vecTests){        
        auto output = sol.XXXX(test.input);
        bool bIsPass = output == test.output;
        cout << \"Test #\" << ++count << \" : Input = \" << test.input << \", Output = \" << output << \". Result : \" <<  (bIsPass? green : red) << (bIsPass? \"Pass\" : \"Fail\") << \"!\" << def << endl;
    }
	return 0;
}
/*
-----------------------------------------------------------------------------------------------------------
method1: <<>>
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
" >> $cppFileName
