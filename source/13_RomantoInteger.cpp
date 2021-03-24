//LeetCode Problem 13 - Roman to Integer
#include "everything.h"
using namespace std;

struct Test{
    string input;
    int output;
};
class Solution {
    public:
    map<char, int> mapRomanToInt = {
        {'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}
    };

    int romanToInt(string s) {
        int total = 0, prevRomanSymbol = ' ';
        for(auto curRomanSymbol : s){
            total += mapRomanToInt[curRomanSymbol];
            if( mapRomanToInt.find(prevRomanSymbol) != mapRomanToInt.end()
                && mapRomanToInt[prevRomanSymbol] < mapRomanToInt[curRomanSymbol])
                 total -= 2*mapRomanToInt[prevRomanSymbol];
            prevRomanSymbol = curRomanSymbol;
        }
        return total;
    }      
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        {"III", 3},
        {"IV", 4},
        {"IX", 9},
        {"LVIII", 58},
        {"MCMXCIV", 1994},
    };
    int count = 0;
    for(auto test: vecTests){        
        int ret = sol.romanToInt(test.input);
        cout << "Test #" << ++count << " : Input = " << test.input << ", Output = " << ret << ". Result : " <<  (ret == test.output? green : red) << (ret == test.output? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}

/*
-----------------------------------------------------------------------------------------------------------
method1: <<>>
-----------------------------------------------------------------------------------------------------------
method2: Leetcode Method
/////////////////////// Problem 13. Roman to Integer //////////////////////////////////////////////
Pseudocode:
1. Set total := 0, prevRomanSymbol := ""
2. For (curRomanSymbol : RomanNumeralString)
    total := total + RomanToInteger(curRomanSymbol)
    if RomanToInteger(prevRomanSymbol) < RomanToInteger(curRomanSymbol):
        total := total - 2 x RomanToInteger(prevRomanSymbol)
4. return total

-----------------------------------------------------------------------------------------------------------
*/