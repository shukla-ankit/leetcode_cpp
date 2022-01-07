//LeetCode Problem 28 - Implement strStr()
/*
	really good solution..
	just read the code!
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if ( needle == "" ) return 0;
        else if( needle.size() > haystack.size()) return -1;

		for(int i = 0; i <= haystack.size() - needle.size() + 1; i++){
			if(haystack[i] != needle[0])  continue;
			else{				
				bool bMatch = true;
				int k = i;
				
				for(int j = 0; j < needle.size(); j++){
					if(haystack[k++] != needle[j]){							
						bMatch = false;
						break;
					}					
				}
				
				if(bMatch) return i;
			}				
		}
		return -1;
    }
};

int main(){
		vector<string> haystack = {"hello", "aaaaa", "","a"}, needle = {"ll", "bba", "","a"};
		vector<int> ret;
				
		Solution s;
		for(int i = 0; i < haystack.size(); i++){
				ret.push_back(s.strStr(haystack[i], needle[i]));
				cout << "haystack = '" << haystack[i]
						<< "', needle = '" << needle[i]
						<< "', returns = " << ret[i] << endl;
		}
		
		return 0;
}
