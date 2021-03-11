//LeetCode Problem 9 - Palindrome Number

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
#include "../colormod.h"
using namespace std;

Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);

class Solution {
    public:
    bool isPalindrome(int x) {
        
    }        
};

struct Test{
    int x;
    bool sol;
};

int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.x = 123, .sol = true},
        {.x = -121, .sol = false},
        {.x = -10, .sol = false},
        {.x = -101, .sol = false},
    };
    int count = 0;
    for(auto test: vecTests){        
        int ret = sol.isPalindrome(test.x);
        cout << "Test #" << ++count << " : Input = " << test.x << ", Output = " << ret << ". Result : " <<  (ret == test.sol? green : red) << (ret == test.sol? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}

