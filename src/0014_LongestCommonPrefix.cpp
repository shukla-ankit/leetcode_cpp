//LeetCode Problem 14 - Longest Common Prefix
/*
See longestCommonPrefix1 
*/

#include "everything.h"
using namespace std;

struct Test{
    vector<string> input;
    string output;
};
class Solution {
    public:
        string longestCommonPrefix1(vector<string>& strs) {
            int l = 0;
            while(l < strs[0].length()){
                for(int i = 1; i < strs.size(); i++){
                    if(strs[i].length() < l || strs[i][l] != strs[0][l])
                        return strs[0].substr(0,l);
                }
                l++;
            }
            return strs[0].substr(0,l);
        }
        string method(vector<string>& strs){
            string prefix;
            if(strs.size() != 0 || strs[0].length() != 0){                
                for(int j = 0; j<strs[0].length(); j++){
                    char ch = strs[0][j];
                    for(int i = 1; i < strs.size(); i++){
                        if(strs[i][j] != ch)
                            return prefix;
                    }
                    prefix.push_back(ch);
                }
            }
            return prefix;
        }
        string leetcode_solution(vector<string>& strs){
            string prefix;
            if(strs.size() != 0){
                prefix = strs[0];
                for(int i = 1; i < strs.size(); i++){
                    while(strs[i].find(prefix) != 0)
                        if(prefix.length() > 0)
                            prefix = prefix.substr(0, prefix.length() - 1);
                        else
                            break;
                }
            }
            return prefix;
        }

        string longestCommonPrefix(vector<string>& strs) {
            return method(strs);
            //return leetcode_solution(strs);
        }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.input={"flower","flow","flight"},.output="fl"},
        {.input={"dog","racecar","car"},.output=""},
        };
    int count = 0;
    for(auto test: vecTests){        
        string ret = sol.longestCommonPrefix(test.input);
        cout << "Test #" << ++count << " : Output = " << ret << ". Result : " <<  (ret == test.output? green : red) << (ret == test.output? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}
/*
-----------------------------------------------------------------------------------------------------------
Assumption: There can be any number of strings with different lengths to compare.

Wrong Assumption: I initiallity thought this common substring can be anywhere in
 the string. but question clearly asks for prefix. "prefix" implies string's start is
 fixed.
-----------------------------------------------------------------------------------------------------------
method1: Horizontal scan

Vertical scan:
Step 0: set prefix = ""
Step 1: for j = 0 to vectorOfStrings[0].length()
Step 2:     char ch = vectorOfStrings[0][j]
Step 3:     for i = 1 to vectorOfStrings.size()
Step 4:             if vectorOfStrings[i][j] != ch, then break;
                    else prefix = prefix + ch;
Step 5: return prefix

Faster method:
Step 0: set prefix = vectorOfStrings[0][0]
Step 1: for i = 1 to vectorOfStrings.size()
Step 2:     while(prefix.length() > 0)
Step 3:         check index of prefix in vectorOfStrings[i]
Step 4:         if(index != 0)
                    prefix =  prefix.substr(0, prefix.length() - 1)
                else break;
Step 5: return prefix

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) return "";
    String prefix = strs[0];
    for (int i = 1; i < strs.length; i++)
        while (strs[i].indexOf(prefix) != 0) {
            prefix = prefix.substring(0, prefix.length() - 1);
            if (prefix.isEmpty()) return "";
        }        
    return prefix;
}
-----------------------------------------------------------------------------------------------------------
*/

