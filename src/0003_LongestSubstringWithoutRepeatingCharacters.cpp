//LeetCode Problem 3 - Longest Substring Without Repeating Characters
#include "everything.h"
struct Test{
    string Input;
    int Output;
};
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
    Solution sol;
    vector<Test> vecTests = {{.Input ="abcabcbb",.Output=3},
	{.Input ="bbbbb",.Output=1},
	{.Input ="pwwkew",.Output=3},
	{.Input ="",.Output=0},
	{.Input =" ",.Output=1},
	{.Input ="abcdefghi",.Output=9}
	};    
    int count = 0;
    for(auto test: vecTests){        
        int ret = sol.lengthOfLongestSubstring(test.Input);
		bool bIsPass = ret == test.Output;
        cout << "Test #" << ++count << " : Input = " << test.Input << ", Output = " << ret << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}
