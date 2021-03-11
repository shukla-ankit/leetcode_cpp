//LeetCode Problem 7 - Reverse Integer

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
using namespace std;

class Solution {
    public:
        string reverseStr(string s){
            string ret;            
            for(int i = s.length() -1; i >-1; i--){
                ret += s[i];
            }
            return ret;
        }
        int method1(int x){            
            int u_rev_x = 0;
            string str_u_rev_x = reverseStr(to_string(x < 0? -x: x));            
            if(to_string(INT_MAX).length() >= str_u_rev_x.length()){                
                int q = stoi(str_u_rev_x.substr(0,to_string(INT_MAX).length() -1));
                int r = stoi(str_u_rev_x.substr(str_u_rev_x.length() -1, 1));
                if ( q < INT_MAX / 10
                     || ( q == INT_MAX/10 && r < INT_MAX%10) )
                {
                    u_rev_x = stoi(str_u_rev_x);
                }
            }
            return x < 0? - u_rev_x: u_rev_x;
        }

        int reverse(int x) {
            return method1(x);
        }
};

struct Test{
    int x;
    int sol;
};

int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.x = 123, .sol=321}, 
        {.x = -123, .sol=-321}, 
        {.x = 120, .sol=21}, 
        {.x = 0, .sol=0},
        {.x = 1534236469, .sol=0},
        {.x =-2147483648, .sol=0}
        };
    int count = 0;
    for(auto test: vecTests){
        int ret = sol.reverse(test.x);
        cout << "Test #" << ++count << " : Reverse of " << test.x << " is =" << ret << ". Test = " << (ret == test.sol? "Pass" : "Fail") << endl;
    }
	return 0;
}

