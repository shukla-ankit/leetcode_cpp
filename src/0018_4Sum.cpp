//LeetCode Problem 18 - 4Sum
#include "everything.h"

struct Test{
    vector<int> input;
    int target;
    vector<vector<int>> output;
};
class Solution {
    public:
    bool add_exceeds_limits(int a, int b){
        if( (a > 0 && b > 0 && a > INT_MAX - b) ||
            (a < 0 && b < 0 && a < INT_MIN - b)
                )
            return true;
        return false;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) return {};
        vector<vector<int>> result;
        sort(begin(nums), end(nums));
        for(int i = 0; i < n - 3; i++){
            if(i ==0 || nums[i] != nums[i-1]){
                for(int j = i+1; j < n-2; j++){
                    if(j == i+1 || nums[j] != nums[j-1]){
                        int k = j+1, l = n-1;
                        while(k < l){
                            // make sure addition doesn't cross INT limits - start
                            if(add_exceeds_limits(nums[k], nums[l]) ||
                               add_exceeds_limits(nums[j], nums[k] + nums[l]) ||
                               add_exceeds_limits(nums[i], nums[j] + nums[k] + nums[l]))
                            {
                                l--; continue;
                            }
                            // make sure addition doesn't cross INT limits - end
                            int sum = nums[i] + nums[j] + nums[k] + nums[l];
                            if(sum > target)
                                l--;
                            else if(sum == target){
                                result.push_back({nums[i], nums[j], nums[k], nums[l]});
                                while(k < l && nums[k] == nums[k+1]) k++;
                                while(k < l && nums[l] == nums[l-1]) l--;
                                k++; l--;
                            }
                            else
                                k++;
                        }
                    }
                }
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.input={1,-2,-5,-4,-3,3,3,5}, .target=-11, .output={{-5,-4,-3,1}}},
            {.input={0,0,0,1000000000,1000000000,1000000000,1000000000},.target=1000000000, .output={{0,0,0,1000000000}}},
            {.input={1000000000,1000000000,1000000000,1000000000},.target=0, .output={}},
            {.input={1,0,-1,0,-2,2}, .target=0, .output={{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}}},
            {.input={2,2,2,2,2}, .target=8, .output={{2,2,2,2}}},
            {.input={1,2,3}, .target=0, .output={}}
            };
    int count = 0;
    for(auto test: vecTests){
        auto output = sol.fourSum(test.input, test.target);
        bool bIsPass = match_arrays_of_arrays(output,test.output);
        cout << "Test #" << ++count << " : Input = " << print_array<int>(test.input) << ", Target = " <<
                test.target << ", Output = " << print_array_of_arrays<int>(output) << ". Result : " <<
                        (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

