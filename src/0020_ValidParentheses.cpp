//LeetCode Problem 20 - Valid Parentheses
/*
 *  Approach:
 *      Create a string to act as a stack, rem
 *      Parse the input string
 *          check if current string is an opening bracket, add it to rem
 *          if current string is a closing bracket
 *              check if length of rem > 0 and last char in rem is opening bracket of same type.
 *              If yes, remove last char from rem.
 *              If not, return false
 *      In end, check length of rem. If rem == "", return true, else return false.
 *
 */


#include "everything.h"

struct Test{
    string input;
    bool output;
};
class Solution {
    public:
    bool isValid(string s) {
        string rem;
        unordered_map<char, char> br = {{'(',')'}, {'{','}'}, {'[',']'}};

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                rem.push_back(s[i]);
            else{
                if(rem.length() && s[i] == br[rem[rem.length() -1]])
                    rem = rem.substr(0, rem.length() - 1);
                else
                    return false;
            }
        }

        if(rem.empty())
            return true;
        return false;
    }

};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.input = "]", .output = false},
            {.input = "()", .output = true},
            {.input = "()[]{}", .output = true},
            {.input = "(]", .output = false}
    };
    int count = 0;
    for(auto test: vecTests){        
        auto output = sol.isValid(test.input);
        bool bIsPass = output == test.output;
        cout << "Test #" << ++count << " : Input = " << test.input << ", Output = " << output << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

