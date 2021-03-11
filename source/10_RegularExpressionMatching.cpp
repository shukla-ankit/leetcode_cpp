//LeetCode Problem 10 - Regular Expression Matching

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
#include "colormod.h"
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
        cout << "Test #" << ++count << " : Input = " << test.s << ", Output = " << ret << ". Result : " <<  (ret == test.sol? green : red) << (ret == test.sol? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}

