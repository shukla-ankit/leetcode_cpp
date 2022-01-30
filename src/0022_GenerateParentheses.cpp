//LeetCode Problem 22 - Generate Parentheses
/*
 * Approach:
 * Create a method to validate if parenthesis string is valid.
 *      Create a balance counter and set it to zero
 *      Parse the string and increase balance for opening bracket, decrease for closing bracket.
 *      if balance goes negative, return false.
 *      Once string is passed, if balance is not zero, return false, Else return true
 *
 * Create a generate paraenthesis method
 *      check if length of current string is 2 * n.
 *          Check if it is valid. If valid, add to result and return
 *      If not, call generateParenthesis again by seting current to current + "(" and current +")" one at a time.
 */


#include "everything.h"

struct Test{
    int input;
    vector<string> output;
};
class Solution {
    public:
    bool valid(string s){
        int balance = 0;
        for(char c: s){
            if(c == '(')
                balance++;
            else
                balance--;
            if(balance < 0)
                return false;

        }
        if(balance == 0)
            return true;
        return false;
    }

    void generateParenthesis(string current, int n, vector<string> &res) {
        if(current.length() == 2*n){
            if(valid(current))
                res.push_back(current);
        }
        else{
            generateParenthesis(current + "(", n, res);
            generateParenthesis(current + ")", n, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis("", n, res);
        return res;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.input= 3, .output={"((()))","(()())","(())()","()(())","()()()"}},
            {.input= 1, .output={"()"}}
    };
    int count = 0;
    for(auto test: vecTests){        
        auto output = sol.generateParenthesis(test.input);
        bool bIsPass = match_array(output, test.output);
        cout << "Test #" << ++count << " : Input = " << test.input << ", Output = " << print_array(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

