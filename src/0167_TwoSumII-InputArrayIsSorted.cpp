//LeetCode Problem 167 - Two Sum II - Input Array Is Sorted
#include "everything.h"

struct input{
	vector<int> nums;
	 int target;
};
struct Test{
    input Input;
    vector<int> Output;
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
            return {left+1, right+1};

    }
};
int main() {
	Solution sol;
	vector<Test> tests = {
		{.Input={.nums={2,7,11,15}, .target=9}, .Output = {1, 2}},
		{.Input={.nums={2, 3, 4}, .target=6}, .Output = {1, 3}},
		{.Input={.nums={3, 3}, .target=6}, .Output = {1, 2}},
		{.Input={.nums={-2, -1, 0}, .target=-1}, .Output = {2, 3}},
	};
	int count = 0;
	for(auto test: tests){
        vector<int> ret = sol.twoSumII(test.Input.nums, test.Input.target);
		bool bIsPass = match_array<int>(ret, test.Output);
        cout << "Test #" << ++count << " : Input = " << print_array<int>(test.Input.nums) << ", Output = " << print_array<int>(ret) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

