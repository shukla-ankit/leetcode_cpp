//LeetCode Problem 8 - String to Integer

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
#include "../colormod.h"

using namespace std;
class Solution {
    public:
        int myAtoi(string s) {
            int ret = 0;
            bool bStart = true, bPositiveSign = true;
            for(char ch : s){
                if(bStart && ch == ' ') 
                    continue;                
                if(bStart && ch == '+'){
                    bStart = false;
                    continue;
                }
                if(ch == '-'){
                    if(bStart){
                        bPositiveSign = false;
                        bStart = false;
                        continue;
                    }
                    else
                        break;                    
                }
                else if(ch < '0' || ch > '9')
                    break;                        
                
                bStart = false;

                if(bPositiveSign){
                    if(ret > INT_MAX/10 
                    || (ret == INT_MAX/10 && ch - '0' > INT_MAX % 10))
                        ret = INT_MAX;
                    else
                        ret = 10 * ret + (ch - '0');
                }
                else{
                    if(ret < INT_MIN/10 
                    || (ret == INT_MIN/10 && ch - '0' > INT_MIN % 10))
                        ret = INT_MIN;
                    else
                        ret = 10 * ret - (ch - '0');
                }
                
            }
            return ret;
        }
};

struct Test{
    string s;
    int sol;
};

int main() {
    Color::Modifier red(Color::FG_RED);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier def(Color::FG_DEFAULT);
    Solution sol;
    vector<Test> vecTests = {
        {.s = "42", .sol=42},
        {.s = "  -42", .sol=-42},
        {.s="4193 with words", .sol=4193},
        {.s= "words and 987", .sol=0},
        {.s= "-91283472332", .sol=-2147483648},
        {.s= "+-12", .sol=0},
        {.s= "21474836460", .sol=2147483647},
        {.s="-2147483647", .sol=-2147483647},
        {.s="-2147483649", .sol=-2147483648}
    };
    int count = 0;
    for(auto test: vecTests){
        int ret = sol.myAtoi(test.s);
        cout << "Test #" << ++count << " : Input = \"" << test.s << "\", Output = " << ret << ". Result : " <<  (ret == test.sol? green : red) << (ret == test.sol? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}

