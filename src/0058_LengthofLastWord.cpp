//LeetCode Problem 58 - Length of Last Word
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    string input;
    int output;
};
class Solution {
    public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        while(end >= 0 && s[end] == ' ')
            --end;

        int start = end;
        while(start >= 0 && s[start] != ' ')
            --start;
        return end - start;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {"Hello World", 5},
            {"   fly me   to   the moon  ", 4},
            {"luffy is still joyboy", 6},
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.lengthOfLastWord(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << test.input << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

