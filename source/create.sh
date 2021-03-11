num=`echo $1 | cut -d '.' -f1`
name=`echo $1 | cut -d '.' -f2`
zeroes=""
if [ "${#num}" == "1" ] 
then
    zeroes="0"
elif [ "${#num}" == "2" ]
then
    zeroes=""
#elif [ "${#num}" == "3" ]
#then
#    zeroes="0"
#elif [ "${#num}" == "4" ]
#then
#    zeroes=""
fi
cppFileName=$zeroes`echo $num"_"${name// /}".cpp"`

echo $cppFileName" created!"
echo "//LeetCode Problem "$num" -"$name"

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
#include \"colormod.h\"
using namespace std;

Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);

class Solution {
    public:
        
};

struct Test{
};

int main() {
    Solution sol;
    vector<Test> vecTests = {};
    int count = 0;
    for(auto test: vecTests){        
        int ret = sol.XXXX(test);
        cout << \"Test #\" << ++count << \" : Input = \" << test.s << \", Output = \" << ret << \". Result : \" <<  (ret == test.sol? green : red) << (ret == test.sol? \"Pass\" : \"Fail\") << \"!\" << def << endl;
    }
	return 0;
}
" >> $cppFileName
