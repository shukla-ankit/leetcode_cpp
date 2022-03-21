//LeetCode Problem 44 - Wildcard Matching
/*
-----------------------------------------------------------------------------------------------------------
Approach 1: Recursion with Memoization
    If the strings are equal (p == s), then return True.
    If the pattern matches any string (p == "*"), then return True.
    If p is empty, or s is empty, return False.
    If the current characters match (p[0] == s[0] or p[0] == '?'), then compare the next ones and return isMatch(s[1:], p[1:]).
    If the current pattern character is a star (p[0] == '*'), then there are two possible situations:
        The star matches no characters, and hence the answer is isMatch(s, p[1:]).
        The star matches one or more characters, and so the answer is isMatch(s[1:], p).
    If p[0] != s[0], return False.
    Time Complexity:
        - Removing duplicated takes p time
        - For every non-memoized call, check m[{s,p}] exists, which takes O(s+p) time to create hash of {s,p}
            and then O(1) to check everytime after creation. Time taken to create a hash for s and p is O(s+p), and time taken for creating substrings is another
            O(s+P) . Total time taken O(2*(s+p)).
        - In worst case where we have all non-memoized calls, there will be s . p calls, so time complexity =
            O ( s . p . (s + p))   -> upper bound
        - Adding all three time complexities, we get O(p + 2.(s + p) + s . p . (s + p)) ~= O(s.p.(s+p))

Approach 2: Dynamic Programming
 -  if s == p, return true
 -  if remove_duplicate_star(p) == "*", return true
 -  if s.empty() OR p.empty(), return false
 -  int d [s.length()+1][p.length()+1] = {false}
 -  d[0][0] = true
 -  if p[pIdx] == '*'

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
        return approach_2(s, p);
    }

// approach_1
    map<vector<string>, bool> m;
    string remove_duplicate_stars(string p){
        if(p.length() < 2) return p;
        string p_new;
        for(int i = 0; i < p.length(); i++){
            if(i > 0 && p[i] == '*' && p[i-1] == '*')
                continue;
            p_new.push_back(p[i]);
        }
        return p_new;
    }
    bool helper(string s, string p){
        if(m.find({s, p}) != m.end())
            return m[{s, p}];

        if(s == p || p == "*")
            m[{s, p}] = true;
        else if(s == "" || p == "")
            m[{s, p}] = false;
        else if(s[0] == p[0] || p[0] == '?')
            m[{s, p}] =  helper(s.substr(1), p.substr(1));
        else if(p[0] == '*')
            m[{s, p}] =  helper(s.substr(1), p) || helper(s, p.substr(1));
        else
            m[{s, p}] = false;
        return m[{s, p}];
    }
    bool approach_1(string s, string p) {
        p = remove_duplicate_stars(p);
        return helper(s, p);
    }

    //approach_2

    bool approach_2(string s, string p) {
        int sLen = s.length(), pLen = p.length();

        // base cases
        if (p == s)
            return true;

        if (pLen > 0 && remove_duplicate_stars(p) == "*")
            return true;

        if (p.empty() || s.empty())
            return false;

        // init all matrix except [0][0] element as False
        vector<vector<bool>> d;
        d.resize(p.length() + 1, vector<bool>(s.length() + 1, false));
        d[0][0] = true;

        // DP compute
        for (int pIdx = 1; pIdx < pLen + 1; pIdx++) {
            // the current character in the pattern is '*'
            if (p[pIdx - 1] == '*') {
                int sIdx = 1;

                // d[p_idx - 1][s_idx - 1] is a string-pattern match
                // on the previous step, i.e. one character before.
                // Find the first idx in string with the previous math.
                while ((!d[pIdx - 1][sIdx - 1]) && (sIdx < sLen + 1)) {
                    sIdx++;
                }

                // If (string) matches (pattern),
                // when (string) matches (pattern)* as well
                d[pIdx][sIdx - 1] = d[pIdx - 1][sIdx - 1];

                // If (string) matches (pattern),
                // when (string)(whatever_characters) matches (pattern)* as well
                while (sIdx < sLen + 1) {
                    d[pIdx][sIdx++] = true;
                }

                // the current character in the pattern is '?'
            } else if (p[pIdx - 1] == '?') {
                for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                    d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1];
                }

                // the current character in the pattern is not '*' or '?'
            } else {
                for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                    // Match is possible if there is a previous match
                    // and current characters are the same
                    d[pIdx][sIdx] = d[pIdx - 1][sIdx - 1] &&
                                    (p[pIdx - 1] == s[sIdx - 1]);
                }
            }
        }
        return d[pLen][sLen];
    }

// approach_3
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
            {"aab","c*a*b",false},
            {"bababaabbaababaaababbbababaaababbbbaabbbabaaaababbabbaabaababaaabbabbbbbbbbbaaabaaabaaaaabbbbbbbababbbaababbabaabbbabbaabbbaabbbaaabbbbabbbbaaaabbaabaaaaaaababbaabbbaaabbbabbaababaabaababaaaaaababbabbbbb","**bb*b***ab***ba**aba*b**b*b*a*b****abbab**bb*b**ba*ab***babb****bb****a*ab*******a*a*****aaa*a*abb*a**",true},
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

