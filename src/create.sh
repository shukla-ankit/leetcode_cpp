#!/bin/bash
num=`echo $1 | cut -d '.' -f1`
name=`echo $1 | cut -d '.' -f2`
zeroes=""
if [ "${#num}" == "1" ] 
then
    zeroes="_0000"
elif [ "${#num}" == "2" ]
then
    zeroes="_000"
elif [ "${#num}" == "3" ]
then
   zeroes="_0"
elif [ "${#num}" == "4" ]
then
   zeroes="_"
fi
cppFileName=$zeroes`echo $num"_"${name// /}".cpp"`
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
        int output = sol.XXXX(test.input);
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
