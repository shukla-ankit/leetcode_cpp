//LeetCode Problem 15 - 3Sum
#include "everything.h"

struct Test{
    vector<int> input;
    vector<vector<int>> output;
};
class Solution {
    public:
        vector<int> twoSumII(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        while(nums[left] + nums[right] != target && left < right){
            if(nums[left] + nums[right] > target)
                right--;
            else
                left++;
        }
        if(left == right)
            return {0, 0};
        else
            return {left, right};
    }

        vector<vector<int>> threeSum(vector<int>& nums) {
            
        }
        void leetcode_solution(){
        }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.input={-1,0,1,2,-1,-4}, .output={{-1,-1,2},{-1,0,1}}},
        {.input={}, .output={}},
        {.input={0}, .output={}}
    };
    int count = 0;
    for(auto test: vecTests){        
        auto output = sol.threeSum(test.input);
        bool bIsPass = match_arrays_of_arrays(output,test.output);
        cout << "Test #" << ++count << " : Input = " << print_array<int>(test.input) << ", Output = " << print_array_of_arrays<int>(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

