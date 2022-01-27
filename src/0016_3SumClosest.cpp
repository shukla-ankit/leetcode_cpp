//LeetCode Problem 16 - 3Sum Closest
#include "everything.h"

struct Test{
    vector<int> input;
    int target;
    int output;
};

class Solution {
    public:
    int threeSumClosest(vector<int> nums, int target) {
        int n = nums.size();
        int sum = nums[0] + nums[1] + nums[n-1];
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n-2 ; i++){
            int j = i+1, k = n-1;
            while(j < k){
                int c_sum = nums[i] + nums[j] + nums[k];
                if(abs(c_sum - target) < abs(sum - target)){
                    sum = c_sum;
                }
                if(c_sum < target) j++;
                else k--;
            }
        }
        return sum;
    }
};


int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.input={-1,2,1,-4}, .target=1, .output=2},
            {.input={0,0,0}, .target=1, .output=0},
            {.input={0,2,1,-3}, .target=1, .output=0},
            {.input={1,1,1,0}, .target=-100, .output=2}
    };
    int count = 0;
    for(auto test: vecTests){
        auto output = sol.threeSumClosest(test.input, test.target);
        bool bIsPass = output == test.output;
        cout << "Test #" << ++count << " : Input = " << print_array<int>(test.input) << ", target = " <<
                test.target << ", Output = " << output << ", Expected = " << test.output << ". Result : " <<
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

