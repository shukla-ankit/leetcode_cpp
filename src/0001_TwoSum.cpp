//LeetCode Problem 1 - Two Sum

/*

1. Create a map from number to its index
2. When adding a number, check if its complement (target - num) exists in map
3. If find complement, return complements index and current index

*/

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
    vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> mapNumToIndex;
		for(int i = 0; i< nums.size(); i++){
			if(mapNumToIndex.find(target-nums[i]) == mapNumToIndex.end())
				mapNumToIndex[nums[i]] = i;			
			else
				return {mapNumToIndex[target - nums[i]], i};
		}
		return {-1, -1};
    }
};
int main() {
	Solution sol;
	vector<Test> tests = {
		{.Input={.nums={2,7,11,15}, .target=9}, .Output = {0, 1}},
		{.Input={.nums={3,2,4}, .target=6}, .Output = {1, 2}},
		{.Input={.nums={3, 3}, .target=6}, .Output = {0, 1}},
	};
	int count = 0;
	for(auto test: tests){
        vector<int> ret = sol.twoSum(test.Input.nums, test.Input.target);
		bool bIsPass = match_array<int>(ret, test.Output);
        cout << "Test #" << ++count << " : Input = " << print_array<int>(test.Input.nums) << ", Output = " << print_array<int>(ret) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
	}
	return 0;
}
