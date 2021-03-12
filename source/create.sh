num=`echo $1 | cut -d '.' -f1`
name=`echo $1 | cut -d '.' -f2`
zeroes=""
if [ "${#num}" == "1" ] 
then
    zeroes="_0"
elif [ "${#num}" == "2" ]
then
    zeroes="_"
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
#include \"everything.h\"
using namespace std;

struct Test{
};
class Solution {
    public:
        
};
int main() {
    Solution sol;
    vector<Test> vecTests = {};
    int count = 0;
    for(auto test: vecTests){        
        int ret = sol.XXXX(test.input);
        cout << \"Test #\" << ++count << \" : Input = \" << test.input << \", Output = \" << ret << \". Result : \" <<  (ret == test.output? green : red) << (ret == test.output? \"Pass\" : \"Fail\") << \"!\" << def << endl;
    }
	return 0;
}
" >> $cppFileName
