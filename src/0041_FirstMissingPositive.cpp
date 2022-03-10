//LeetCode Problem 41 - First Missing Positive
/*
-----------------------------------------------------------------------------------------------------------
My Method:

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> input;
    int output;
};
class Solution {
    public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> temp(nums.size(), -1);
        for(int i=0; i<nums.size();i++){
            if(nums[i] > nums.size())
                nums[i] = -1;
            if(nums[i] > 0)
                temp[nums[i] - 1] = nums[i];
        }
        int i=0;
        for(; i<temp.size();i++)
            if(temp[i] == -1)
                break;
        return i+1;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{1,2,0}, 3},
            {{3,4,-1,1}, 2},
            {{7,8,9,11,12}, 1},
            {{1}, 2}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.firstMissingPositive(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

