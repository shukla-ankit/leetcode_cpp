//LeetCode Problem 10 - Regular Expression Matching
#include "everything.h"
using namespace std;

struct Test{
    string input1;
    string input2;
    bool output;
};
class Solution {
public:
    bool isMatch1(string s, string p) {
        if(p.empty())
            return s.empty();
        while(!p.empty() && p[p.length() - 1] != '*'){
            if(s[s.length()-1] != p[p.length()-1] && p[p.length()-1]  != '.')
                return false;
            s = s.substr(0, s.length()-1);
            p = p.substr(0, p.length()-1);
        }

        int i=0, j =0;
        for(; i < s.length() && j < p.length();){
            if(j < p.length() - 1 && p[j+1] == '*'){
                if(p[j] == '.'){
                    if(j == p.length() - 2)
                        return true;
                    j+=2;
                    i = s.length() - (p.length() -j) - 1;
                }
                while(s[i] == p[j] && i < s.length())
                    i++;
                j+=2;
            }
            else if(s[i] == p[j] || p[j] == '.'){
                i++; j++;
            }
        }
        if(i < s.length() || j < p.length())
            return false;
        return true;
    }


    bool isMatch2(string s, string p) {
        while(!p.empty()){
            if(p.length() > 1 && p[1] == '*'){
                if(p == ".*")
                    return true;
            }
            else if(s.empty())
                return false;

            while(!s.empty() && !p.empty() && p[p.length() - 1] != '*'){
                if(p[p.length() - 1] != s[s.length()-1] && p[p.length() - 1] != '.')
                    return false;
                s = s.substr(0, s.length()-1);
                p = p.substr(0, p.length()-1);
            }

            while(!s.empty() && !p.empty()){
                if(p.length() > 1 && p[1] == '*')
                    break;
                if(p[0] != s[0] && p[0] != '.')
                    return false;
                s = s.substr(1, s.length()-1);
                p = p.substr(1, p.length()-1);
            }

            while(p.length() > 1 && p[0] != '.' && p[1] == '*'){
                while(s.length() > 0 && s[0] == p[0])
                    s = s.substr(1, s.length()-1);
                p = p.substr(2, p.length()-2);
                if(s.empty())
                    break;
            }

            while(p.length() > 1 && p[p.length()-2] != '.' && p[p.length()-1] == '*'){
                while(s.length() > 0 && s[s.length()-1] == p[p.length()-2])
                    s = s.substr(0, s.length()-1);
                p = p.substr(0, p.length()-2);
                if(s.empty())
                    break;
            }
        }
        return s.empty();
    }



    enum Result {
        TRUE, FALSE, NONE
    };

    bool isMatch(string text, string pattern) {
        vector<vector<Result>> memo(text.length() + 1,vector<Result>(pattern.length() + 1, Result::NONE));
        return dp(memo, 0, 0, text, pattern);
    }

    bool dp(vector<vector<Result>> &memo, int i, int j, string text, string pattern) {
        if (memo[i][j] != Result::NONE) {
            return memo[i][j] == Result::TRUE;
        }
        bool ans;
        if (j == pattern.length()) {
            ans = i == text.length();
        } else {
            bool first_match = (i < text.length() &&
                                   (pattern[j] == text[i] ||
                                    pattern[j] == '.'));

            if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
                ans = (dp(memo, i, j + 2, text, pattern) ||
                       first_match && dp(memo, i + 1, j, text, pattern));
            } else {
                ans = first_match && dp(memo, i + 1, j + 1, text, pattern);
            }
        }
        memo[i][j] = ans ? Result::TRUE : Result::FALSE;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<Test> vecTests = {
            {"a", ".*..a*", false},
            {"bbbba", ".*a*a", true},
            {.input1="aaa", .input2="aaaa", .output=false},
            {.input1="aa", .input2="a", .output=false},
            {.input1="aa", .input2="a*", .output=true},
            {.input1="ab", .input2=".*", .output=true},
            {.input1="aaa", .input2="a*a", .output=true},
            {.input1="aab", .input2="c*a*b", .output=true},
            {.input1="mississippi", "mis*is*p*.", .output=false},
            {.input1="mississippi", "mis*is*.p*.", .output=true},
            {"aaa", "ab*a*c*a", true},
    };
    int count = 0;
    for(auto test: vecTests){        
        bool ret = sol.isMatch(test.input1, test.input2);
        cout << "Test #" << ++count << " : Input = \"" << test.input1 << "\" & \"" << test.input2 << "\", Output = " << ret << ". Result : " <<  (ret == test.output? green : red) << (ret == test.output? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}

/*


-----------------------------------------------------------------------------------------------------------
method1: <<>> Doesn't work!!

1. Parse both strings
    2. if both match, 
            move to next character in string and pattern
       else 
            return false
    3. else if pattern's current character is *
                if pattern's previous character matches 
                    then stay on with same pattern character
                else 
                    move to next pattern character
                move to next string character
    4. else if pattern's current character is .
                if following character is *
                    then check characters after * match with string. // can pass recursively to same function to match with                     
                else
                    continue to next character in pattern and string

-----------------------------------------------------------------------------------------------------------
method2: Leetcode Method

Recursive approach

Step 1: Check if pattern is empty, text must be empty to match (return true). Else mismatch i.e. return false
        Otherwise : // Remaining steps for pattern is not empty
Step 2: Check if text is not empty, return status
Step 3: Check if text[0] matches pattern[0] or pattern[0] = '.' ? else return fail

Step 4




-----------------------------------------------------------------------------------------------------------
*/

//class Solution {
//public:
//    bool method1(string s, string p){
//        int i=0, j=0;
//        char cWildCardMatchChar = '\0';
//        while(i < s.length() && j < p.length()){
//            if(s[i] == p[j]){
//                i++; j++; // char to char matching
//            }
//            else if(p[j] == '.'){
//                i++; j++; // mimic matching by .
//            }
//            else if(p[j] == '*'){
//                if(cWildCardMatchChar == '\0')
//                    cWildCardMatchChar = p[j-1];
//                if(cWildCardMatchChar == '.'){
//                    // remains
//                    //cout << ".* case" << endl;
//                    break;
//                }
//                else if(cWildCardMatchChar == s[i]){
//                    //cout << "start N occurence * case" << endl;
//                    i++;    // * causes N occurences of cWildCardMatchChar
//                }
//                else{
//                    cWildCardMatchChar = '\0';
//                    j++;     // * causes end of cWildCardMatchChar matching
//                    //cout << "end N occurence * case" << endl;
//                }
//            }
//            else if(j < p.size() -1 && p[j+1] == '*'){
//                i++; j++;   // * causes 0 occurence of cWildCardMatchChar
//            }
//            else
//                return false;
//        }
//        return i == s.length() &&
//               (    j == p.length() ||
//                    (j == p.length()-1 && p[j=1] == '*'));
//
//    }
//    bool method2(string text, string pattern) {
//        if (pattern.empty())
//            return text.empty();
//
//        bool bMatch = (!text.empty() &&
//                       (pattern[0] == text[0]|| pattern[0] == '.'));
//
//        if (pattern.length() >= 2 && pattern[1] == '*'){
//            return (isMatch(text, pattern.substr(2)) // If they don't match, keep text same and start matching after '*'
//                    || (bMatch && isMatch(text.substr(1), pattern))); // If they match, keep pattern same and keep moving left on text till they match
//        }
//        else {
//            if(bMatch)
//                return isMatch(text.substr(1), pattern.substr(1));
//            else
//                return false;
//        }
//    }
//    bool leetcode_method(string text, string pattern) {
//        if (pattern.empty())
//            return text.empty();
//
//        bool first_match = (!text.empty() &&
//                            (pattern[0] == text[0]|| pattern[0] == '.'));
//
//        if (pattern.length() >= 2 && pattern[1] == '*'){
//            return (isMatch(text, pattern.substr(2)) ||
//                    (first_match && isMatch(text.substr(1), pattern)));
//        } else {
//            return first_match && isMatch(text.substr(1), pattern.substr(1));
//        }
//    }
//    bool isMatch(string s, string p) {
//        return method1(s, p);
//        //return leetcode_method(s,p);
//    }
//};
