//LeetCode Problem 38 - Count and Say
/*
-----------------------------------------------------------------------------------------------------------
My Method:

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    int input;
    string output;
};
class Solution {
    public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string s = countAndSay(n-1), res;
        char prev = ' ';
        int count = 0;
        for(auto current : s){
            if(current == prev){
                count++;
                continue;
            }
            if(prev != ' '){
                res = res + to_string(count);
                res.push_back(prev);
            }
            count = 1;
            prev = current;
        }
        res = res + to_string(count);
        res.push_back(prev);
        return res;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {1, "1"},
            {2, "11"},
            {3, "21"},
            {4, "1211"},
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.countAndSay(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << test.input << ", Output = " << output << ", Expected = " << test.output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

