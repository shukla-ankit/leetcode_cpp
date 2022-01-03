//LeetCode Problem 30 - Substring with Concatenation of All Words
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
        vector<int> method(string s, vector<string>& words, vector<int> outVec = {}) {   
            if(s.empty() || words.size() == 0)  return outVec;

            map<int, string> mapIndexToWord;
            int min_index = s.length();
            string t = s;
            for(auto word: words){                
                if(t.find(word) != string::npos && ( t ==s || (t != s && t.find(word) == 0)) ){
                    min_index = min_index > t.find(word)? t.find(word) : min_index;
                    mapIndexToWord[t.find(word)] = word;                    
                    t = t.substr(min_index,t.length()- min_index);
                }
                else
                    return outVec;
            }

            if(words.size() != mapIndexToWord.size()) return outVec;
            
            for(int i = min_index; i<words.size(); i+= words[0].length()){
                if(mapIndexToWord.find(i) == mapIndexToWord.end())
                    return outVec;                        
            }

            outVec.push_back(min_index);

            return method(s.substr(min_index+words[0].length()), words);            
        }

        vector<int> method2(string s, vector<string>& words, vector<int> outVec = {}) {   
            if(s.empty() || words.size() == 0)  return outVec;
            
            int min_index = s.length();
            for(auto word: words){                
                if(s.find(word) == string::npos) return outVec;
                min_index = min_index > s.find(word)? s.find(word) : min_index;                    
            }

            string t = s.substr(min_index, s.length() - min_index);
            while(1){
                string sub = t.substr(words[0].length());
                

            }

            if(words.size() != mapIndexToWord.size()) return outVec;
            
            for(int i = min_index; i<words.size(); i+= words[0].length()){
                if(mapIndexToWord.find(i) == mapIndexToWord.end())
                    return outVec;                        
            }

            outVec.push_back(min_index);

            return method(s.substr(min_index+words[0].length()), words);            
        }


        vector<int> leetcode_solution(string s, vector<string>& words) {
            return {};
        }

        vector<int> findSubstring(string s, vector<string>& words) {
            return method(s, words);
        }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        { .input={.s="",.words={}}, .output={}},
        { .input={.s="",.words={"foo","bar"}}, .output={}},
        { .input={.s="barfoothefoobarman",.words={}}, .output={}},        
        { .input={.s="barfoothefoobarman",.words={"foo","bar"}}, .output={0,9}},
        { .input={.s="wordgoodgoodgoodbestword",.words={"word","good","best","word"}}, .output={}},
        { .input={.s="barfoofoobarthefoobarman",.words={"bar","foo","the"}}, .output={6,9,12}},
    };
    int count = 0;
    for(auto test: vecTests){        
        vector<int> output = sol.findSubstring(test.input.s, test.input.words);
        bool bIsPass = match_array<int>(output, test.output);
        cout << "Test #" << ++count << " : Input = {" << test.input.s <<"," <<  print_array<string>(test.input.words) << "}, Output = " << print_array<int>(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}
/*
-----------------------------------------------------------------------------------------------------------
method1: <<>>
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/

