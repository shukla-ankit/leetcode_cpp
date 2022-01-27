//LeetCode Problem 17 - Letter Combinations of a Phone Number
#include "everything.h"

/*
 * Three loops:
 * First passing over char in digits string
 * Second loop over strings already added in results, picking one at a time
 * Third loop taking all mapped characters from map[digits[i]] and adding them one by one
 * to string picked from second loop.
 * Update the result for next iteration in first loop
 * */


struct Test{
    string input;
    vector<string> output;
};
class Solution {
public:
    vector<string> addChar(vector<string> s, vector<char> digitSymbols){
        vector<string> res;
        if(s.empty()){
            for(int j = 0; j < digitSymbols.size(); j++){
                string t;
                t.push_back(digitSymbols[j]);
                res.push_back(t);
            }
            return res;
        }

        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < digitSymbols.size(); j++){
                string t;
                t.push_back(digitSymbols[j]);
                res.push_back(s[i] + t);
            }
        }
        return res;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        map<char,vector<char>> m = {
                {'1', {}},
                {'2', {'a','b','c'}},
                {'3', {'d','e','f'}},
                {'4', {'g','h','i'}},
                {'5', {'j','k','l'}},
                {'6', {'m','n','o'}},
                {'7', {'p','q','r','s'}},
                {'8', {'t','u','v'}},
                {'9', {'w','x','y','z'}},
                {'0', {' '}}
        };
        for(int i = 0; i < digits.length(); i++){
            result = addChar(result, m[digits[i]]);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.input="23", .output={"ad","ae","af","bd","be","bf","cd","ce","cf"}},
            {.input="2", .output={"a","b","c"}},
            {.input="", .output={}},
    };
    int count = 0;
    for(auto test: vecTests){        
        auto output = sol.letterCombinations(test.input);
        bool bIsPass = match_array(output,test.output);
        cout << "Test #" << ++count << " : Input = " << test.input << ", Output = " << print_array<string>(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}
/*
-----------------------------------------------------------------------------------------------------------
method1: <<>>
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/

