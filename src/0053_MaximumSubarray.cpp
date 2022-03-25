//LeetCode Problem 53 - Maximum Subarray
/*
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

 Approach:
    1. Set current_sum and max_subarray_sum = nums[0]
    2. Iterate over nums from 1 to nums.size() -1:
            current_sum = max(nums[i], current_sum + nums[i])
            max_subarray_sum = max(current_sum, max_subarray_sum)
    3. return max_subarray_sum
-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> input;
    int output;
};
class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], ret = nums[0];
        for(int i=1; i<nums.size(); i++){
            sum = max(nums[i], sum + nums[i]);
            ret = max(ret, sum);
        }
        return ret;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{-2,1,-3,4,-1,2,1,-5,4},6 },
            {{1}, 1},
            {{5,4,-1,7,8}, 23}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.maxSubArray(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

