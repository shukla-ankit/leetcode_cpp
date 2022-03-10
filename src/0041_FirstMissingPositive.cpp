//LeetCode Problem 41 - First Missing Positive
/*
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

 1. Two passes required.
 2. Create a temp vector of same size as nums with initial values as -1.
 3. First pass - Iterate over nums
        if nums[i] > nums.size(), set nums[i] = -1
        if nums[i] > 0, set temp[nums[i] - 1] = nums[i]
 So basically put 1 from nums at 0th index in temp, 2 from nums at 1st index place in temp, 3 from nums at 2nd index
 place in temp etc.
 4. Parse temp and if found -1, it means this places value is missing in nums, so return index + 1 as missing value
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

