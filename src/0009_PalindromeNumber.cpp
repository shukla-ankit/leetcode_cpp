//LeetCode Problem 9 - Palindrome Number
/*
Easy problem.

Check if a number is a palindrome.

method1: Convert integer to string and then reverse the string and comopare.

method2: Reverse the string and compare. Take care of INT_MAX limits. 
Special Case: If reverse function is return INT_MAX, when reversed number is going out of bound, 
make sure Input case x = INT_MAX is handled.
*/

#include "everything.h"
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
    bool isPalindrome1(int x) {
        if( x < 0)
            return false;   
        
        string s = to_string(x);
        return s == reverseStr(s);
    }

    int reverseInteger(int x){
        int rev = 0;
        while(x != 0){
            if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rev % 10 >= INT_MAX % 10 ))
                return INT_MAX;
            rev = 10 * rev + x % 10;
            x /= 10;
        }
        return rev;
    }
    bool isPalindrome2(int x) {
        if(x < 0) 
            return false;
        if(x == INT_MAX)
            return false;
        
        return x == reverseInteger(x);
    }

};

struct Test{
    int x;
    bool sol;
};

int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.x = 123, .sol = false},
        {.x = -121, .sol = false},
        {.x = -10, .sol = false},
        {.x = -101, .sol = false},
        {.x = 101, .sol = true},
    };
    int count = 0;
    for(auto test: vecTests){        
        bool ret = sol.isPalindrome2(test.x);
        cout << "Test #" << ++count << " : Input = " << test.x << ", Output = " << ret << ". Result : " <<  (ret == test.sol? green : red) << (ret == test.sol? "Pass!" : "Fail!") <<  def << endl;
    }
	return 0;
}

