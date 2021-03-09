//LeetCode Problem 3 - Longest Substring Without Repeating Characters

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		map<char, int> mapCharToLastOccurIndex;
		int start = 0, lenOfLongestStr = 0;
		int i=0;
		for (; i < s.length(); i++){
			if (mapCharToLastOccurIndex.find(s[i]) == mapCharToLastOccurIndex.end())
				mapCharToLastOccurIndex[s[i]] = i;
			else{
				if (lenOfLongestStr < i - start)
					lenOfLongestStr = i - start;
				start = start > mapCharToLastOccurIndex[s[i]] + 1 ? start : mapCharToLastOccurIndex[s[i]] + 1;
				mapCharToLastOccurIndex[s[i]] = i;
			}
		}
		if (lenOfLongestStr < i - start)
			lenOfLongestStr = i - start;
		return lenOfLongestStr;
    }
};

int main() {	
	vector<string> vecTests = {"abcabcbb", "bbbbb",  "pwwkew", "", " ", "abcdefghi"};
	Solution sol;
	for(auto s: vecTests){		
		cout << sol.lengthOfLongestSubstring(s) << endl;
	}
	return 0;
}
