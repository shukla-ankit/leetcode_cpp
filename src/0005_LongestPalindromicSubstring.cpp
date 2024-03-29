//LeetCode Problem 5 - Longest Palindromic Substring
/*

Palindromes are created by starting from middle and adding same character to left and right
Examples "abcdeedcba" <- Even length, "abcdedcba" <- odd length

1. Parse the string and at each char check largest possible palindrom with 
current character as center
2. TO do that, write a function to find largest palindrome with given left and right indices. 
3. Keep decreasing left and increasing right, if s[left] == s[right]. When fail return substring.

4. Maintain longest palindrome variable and compare with new found palindomes. Update if a longer 
palindrome is found.
*/

#include "everything.h"
struct Test{
    string Input;
    string Output;
};
class Solution {
    public:
    string longestPalindrome(string s, int left, int right) {
        if( left > right 
            || left < 0 && right > s.length() - 1 
            || s[left] != s[right]) 
            return "";
        
        while(left > 0 && right < s.length() - 1 && s[left - 1] == s[right + 1]){
            left--; right++;
        }
        return s.substr(left, right-left + 1);
    }

    string longestPalindrome(string s) {
        string longest_palindrome;
        for(int i = 0; i < s.length(); i++){
            string s_odd = longestPalindrome(s, i, i);            
            longest_palindrome = longest_palindrome.size() > s_odd.size() ? longest_palindrome : s_odd;            
            if(i < s.length() - 1){
                string s_even = longestPalindrome(s, i, i + 1);
                longest_palindrome = longest_palindrome.size() > s_even.size() ? longest_palindrome : s_even;            
            }           
        }        
        return longest_palindrome;        
    }
};

int main() {
    Solution sol;
    vector<Test> vecTests = {{.Input ="babad",.Output="aba"},
	{.Input ="cbbd",.Output="bb"},
    {.Input ="a",.Output="a"},
    {.Input ="ac",.Output="c"},
    };    
    int count = 0;
    for(auto test: vecTests){        
        string ret = sol.longestPalindrome(test.Input);
		bool bIsPass = ret == test.Output;
        cout << "Test #" << ++count << " : Input = " << test.Input << ", Output = " << ret << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}

