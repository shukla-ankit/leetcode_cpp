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
        bool myMethod(string s, string p){
            int i=0, j=0;
            char cWildCardMatchChar = '\0';
            while(i < s.length() && j < p.length()){
                if(s[i] == p[j]){
                    i++; j++; // char to char matching
                }                
                else if(p[j] == '.'){
                    i++; j++; // mimic matching by .
                }
                else if(p[j] == '*'){
                    if(cWildCardMatchChar == '\0')
                        cWildCardMatchChar = p[j-1];
                    if(cWildCardMatchChar == '.'){
                        // remains
                        cout << ".* case" << endl;
                        break;
                    }
                    else if(cWildCardMatchChar == s[i]){
                        cout << "start N occurence * case" << endl;
                        i++;    // * causes N occurences of cWildCardMatchChar
                    }
                    else{
                        cWildCardMatchChar = '\0';
                        j++;     // * causes end of cWildCardMatchChar matching
                        cout << "end N occurence * case" << endl;
                    }
                }
                else if(j < p.size() -1 && p[j+1] == '*'){
                    i++; j++;   // * causes 0 occurence of cWildCardMatchChar
                }
                else
                    return false;
            }            
            return i == s.length() && 
                        (    j == p.length() || 
                            (j == p.length()-1 && p[j=1] == '*'));
            
        }

        bool given_method(string text, string pattern) {
            if (pattern.empty()) 
                return text.empty();
                
            bool first_match = (!text.empty() &&
                                (pattern[0] == text[0]|| pattern[0] == '.'));

            if (pattern.length() >= 2 && pattern[1] == '*'){
                return (isMatch(text, pattern.substr(2)) ||
                        (first_match && isMatch(text.substr(1), pattern)));
            } else {
                return first_match && isMatch(text.substr(1), pattern.substr(1));
            }
        }
        
        bool isMatch(string s, string p) {
            //return myMethod(s, p);
            return given_method(s,p);
        }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.input1="aa", .input2="a", .output=false},
        {.input1="aa", .input2="a*", .output=true},
        {.input1="ab", .input2=".*", .output=true},
        {.input1="aab", .input2="c*a*b", .output=true},
        {.input1="mississippi", "mis*is*p*.", .output=false},
    };
    int count = 0;
    for(auto test: vecTests){        
        bool ret = sol.isMatch(test.input1, test.input2);
        cout << "Test #" << ++count << " : Input = " << test.input1 << " & " << test.input2 << ", Output = " << ret << ". Result : " <<  (ret == test.output? green : red) << (ret == test.output? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}

/*
Pseudocode
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

*/

