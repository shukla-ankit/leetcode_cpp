num=`echo $1 | cut -d '.' -f1`
name=`echo $1 | cut -d '.' -f2`
cppFileName=`echo $num"_"${name// /}".cpp"`
echo $cppFileName" created!"
echo "//LeetCode Problem #"$num" - "$name" 

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class Solution {
    public:
        
};

int main() {
    Solution sol;


	return 0;
}
" >> "source/"$cppFileName
