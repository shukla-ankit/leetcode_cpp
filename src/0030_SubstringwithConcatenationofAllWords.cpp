//LeetCode Problem 30 - Substring with Concatenation of All Words
/*
    Approach 1: Sliding Window approach
        - Create a frequency map of given words list
        - Compute the sum of chars of every word and compare it with running sum on main string
        - If matched, take a substring of length words.size() * words[0].length(), cut it into pieces of words[0].length()
            and create a frequency map
        - Compare it with frequency map of Step 1 and if they match add it to be the return result vector.

    (Time Limit Exceeded!) - All cases passed, but took too long.

    Approach 2:
        -

 */
#include "everything.h"

struct Input{
 string s;
 vector<string> words;
};
struct Test{
    Input input;
    vector<int> output;
};
class Solution {
    public:
    unordered_map<string, int> CreateWordFrequencyMap(vector<string> &words){
        unordered_map<string, int> res;
        for(int i=0; i < words.size(); i++)
                res[words[i]]++;    //if words[i] doesn't exist, a default value 0 is assumed.
        return res;
    }
    bool sameMap(unordered_map<string, int> &A, unordered_map<string, int> &B){
        if(A.size() != B.size())
            return false;
        for(auto a : A){
            if(B.find(a.first) == B.end() || B[a.first] != a.second)
                return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty() || s.length() < words.size() * words[0].length())
            return {};
        vector<int> res;
        unordered_map<string, int> mapWordCount(CreateWordFrequencyMap(words));
        int c_sum = 0, current = 0;
        for(int i=0; i < words.size(); i++){
            for(int j=0; j<words[0].length(); j++){
                c_sum += (words[i][j] - 'A');
            }
        }
        for(int i=0; i < words.size() * words[0].length(); i++){
            current += (s[i] - 'A');
        }
        for(int i=0; i <= s.length() - words.size() * words[0].length(); i++){
            if(i != 0)
                current += (s[i + words.size() * words[0].length() - 1 ] - s[i-1]);
            if(current == c_sum){
                vector<string> c_words;
                string cur_str  = s.substr(i, words.size() * words[0].length());
                while(!cur_str.empty()){
                    c_words.push_back(cur_str.substr(0, words[0].length()));
                    cur_str = cur_str.substr(words[0].length(), cur_str.length() - words[0].length());
                }
                unordered_map<string, int> mapCurWordCount(CreateWordFrequencyMap(c_words));
                if(sameMap(mapWordCount, mapCurWordCount))
                    res.push_back(i);
            }
        }
        return res;
    }
};
int main() {
    auto start = high_resolution_clock::now();
    Solution sol;
    vector<Test> vecTests = {
        { .input={.s="barfoothefoobarman",.words={"foo","bar"}}, .output={0,9}},
        { .input={.s="barfoofoobarthefoobarman",.words={"bar","foo","the"}}, .output={6,9,12}},
        { .input={.s="wordgoodgoodgoodbestword",.words={"word","good","best","word"}}, .output={}},
        { .input={.s="",.words={}}, .output={}},
        { .input={.s="",.words={"foo","bar"}}, .output={}},
        { .input={.s="barfoothefoobarman",.words={}}, .output={}},
    };
    int count = 0;
    for(auto test: vecTests){        
        vector<int> output = sol.findSubstring(test.input.s, test.input.words);
        bool bIsPass = match_array<int>(output, test.output);
        cout << "Test #" << ++count << " : Input = {\"" + test.input.s + "\"," <<  print_array<string>(test.input.words) << "}, Output = " << print_array<int>(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    auto stop = high_resolution_clock::now();
    cout << "\nTime taken " << duration_cast<microseconds>(stop - start).count() << " microseconds" << endl;
	return 0;
}
