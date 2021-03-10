//LeetCode Problem 30 - Substring with Concatenation of All Words

#include <iostream>
#include <cmath>
#include <cassert>
#include <limits.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //constraints
        assert(s.length() < 10000);
        assert(words.size() < 5000);
        for(auto chr : s){
           assert( 'a' <= chr && chr >= 'z');
        }        
        for (auto word: words){
            assert(word.length() < 30);
            for(auto chr : word){
                assert( 'a' <= chr && chr >= 'z');
            }
        }
    }
};

int main(){
    Solution s;


    return 0;
}