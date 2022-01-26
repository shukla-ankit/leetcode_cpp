//LeetCode Problem 15 - 3Sum
#include "everything.h"

struct Test{
    vector<int> input;
    vector<vector<int>> output;
};
class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int j = i + 1, k = n - 1;
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                        while (j < k && nums[j] == nums[j + 1]) j++;
                        while (j < k && nums[k] == nums[j - 1]) k--;
                        j++;
                        k--;
                    }
                    else if (sum > 0) k--;
                    else j++;
                }
            }
        }
        return result;
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

