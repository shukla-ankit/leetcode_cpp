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

echo $cppFileName" created!"
echo "//LeetCode Problem "$num" -"$name"

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class Solution {
    public:
        
};

struct Test{
};

int main() {
    Solution sol;
    vector<Test> vecTests = {};
    for(auto test: vecTests){
        sol.XXXX(test);
    }
	return 0;
}
" >> "source/"$cppFileName
