//LeetCode Problem 217 - Contains Duplicate
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> input;
    bool output;
};
class Solution {
    public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set_nums;
        for(int k : nums){
            if(set_nums.find(k) != set_nums.end())
                return true;
            set_nums.insert(k);
        }
        return false;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.input={1,2,3,1}, .output=true},
            {.input={1,2,3,4}, .output=false},
            {.input={1,1,1,3,3,4,3,2,4,2}, .output=true}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.containsDuplicate(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

