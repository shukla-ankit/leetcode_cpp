//LeetCode Problem 15 - 3Sum
#include "everything.h"

/*
 * The bruteforce way will be to do three loops and check for each value with O(n^3)
 * Or we do two loops and find the negative of their sum using binary search with O(n^2 log n)
 * Or we do one loop and try to find two numbers with sum equal to negative as first,
 * which gives O(n^2)
 * */

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
            if (i == 0 || nums[i] != nums[i - 1]) // To avoid repeatition of i
            {
                int j = i + 1, k = n - 1;
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                        while (j < k && nums[j] == nums[j + 1]) j++; //Avoid repeatition in j
                        while (j < k && nums[k] == nums[k - 1]) k--; //Avoid repeatition in k
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

