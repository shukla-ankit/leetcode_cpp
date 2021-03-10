//LeetCode Problem 5 - Longest Palindromic Substring

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class Solution {
    public:
    string longestPalindrome(string s, int start, int end) {
        if( start > end 
            || start < 0 && end > s.length() - 1 
            || s[start] != s[end]) 
            return "";
        
        while(start > 0 && end < s.length() - 1 && s[start - 1] == s[end + 1]){
            start--; end++;
        }
        return s.substr(start, end-start + 1);
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
    vector<string> vecTests = {"babad", "cbbd", "a", "ac"};
    for(auto str: vecTests){
        string lp = sol.longestPalindrome(str);
        cout << "String \"" << str << "\" has longest pandrome as \"" << lp << "\"" << endl;
    }
	return 0;
}

