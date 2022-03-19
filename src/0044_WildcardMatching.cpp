//LeetCode Problem 44 - Wildcard Matching
/*
-----------------------------------------------------------------------------------------------------------
Approach 3: Backtracking
 Time Complexity =  O(min (m, n)) for best case
                    O(n log m) for average case
                    O(m.n) for worst case

 1. Parse the two strings and if chars match in S & P or if P char is ?, increment sIDx and pIDx
 2. If p char is *, store pIdx as starIdx and increment pIdx. Also, store sIdx as sTmpIdx.
 3. If above two conditions aren't met AND starIdx is not set, return false
 4. If starIdx is set,


-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    string s;
    string p;
    bool output;
};
class Solution {
    public:
    bool isMatch(string s, string p){
        return approach_3(s, p);
    }
    bool approach_3(string s, string p) {
        int sIdx = 0, pIdx = 0, starIdx = -1, sTmpIdx = -1;

        while(sIdx < s.length()){
            if(pIdx < p.length() && ( p[pIdx] == '?' || p[pIdx] == s[sIdx] )){
                sIdx++; pIdx++;
            }
            else if(pIdx < p.length() && p[pIdx] == '*'){
                starIdx = pIdx;
                sTmpIdx = sIdx;
                pIdx++;
            }
            else if(starIdx == -1)
                return false;
            else{
                pIdx = starIdx + 1;
                sIdx = sTmpIdx + 1;
                sTmpIdx = sIdx;
            }
        }
        for(int k = pIdx; k < p.length(); k++ ){
            if(p[k] != '*')
                return false;
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {"aa", "a", false},
            {"aaabababaaabaababbbaaaabbbbbbabbbbabbbabbaabbababab", "*ab***ba**b*b*aaab*b", true},
            {"abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb",
            "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**", true},
            {"", "********", true},
            {"acdcb", "a*c?b", false},
            {"adceb", "*a*b", true},
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.isMatch(test.s, test.p);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input : s=" << test.s << ", p=" << test.p << ", Output = " << (output?"True":"False")
        << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

