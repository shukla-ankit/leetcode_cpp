//LeetCode Problem 259 - 3Sum Smaller
#include "everything.h"

/*
 * Keep it simple
 * Unlike ThreeSum Problem, don't worry about repeating values in i, j and k
 * Only value to be saved is number of results possible
 *
 * One loop for i from 0 to n-2
 * One loop for j and k.
 *      If sum < target, add k - j values to total results as all values of k from j+1 to k will be
 *      less than target. And then increment j
 *      If sum >= target, decrement k.
 */

struct Test{
    vector<int> input;
    int target;
    int output;
};

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3) return 0;

        int results = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < n-2 ; i++){
            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target){
                    /* Causes Time Exceeded */
                    // int c_k = k;
                    // while(c_k > j){
                    //     result.push_back({nums[i], nums[j], nums[c_k]});
                    //     c_k--;
                    // }
                    results += k - j;
                    j++;
                }
                else
                    k--;
            }
        }
        //return result.size();
        return results;
    }
};


int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.input={-7,-6,14,3,12,-13,-8,5,12,9,11,6,0,2,12,-1,0,-2,13,-3,9,-12,4,-2,0,8,1,-13,-5,-6,-13,11,1,-14,1,14,0,13,2,12,-4,14,5,4,-6,6,11,-13,1,-11,-7,10,-7,-4,-5,1,6,-3,1,-11,6,-6,3,-5,1,-9,-9,-3,9,-5,-2,-7,-6,9,2,8,-2,-11,-10,-5,14,-8,5,-9,10,-6,2,12,0,-7,12,-4,-11,-15,-9,14,-6,12,0,-1,-13,-4,0,13,3,10,-13,-11,-5,-5,2,6}, .target=1, .output=117459},
            {.input={-1,1,-1,-1}, .target=-1, .output=1},
            {.input={3,1,0,-2}, .target=4, .output=3},
            {.input={-2,0,1,3}, .target=2, .output=2},
            {.input={}, .target=0, .output=0},
            {.input={0}, .target=0, .output=0}
    };
    int count = 0;
    for(auto test: vecTests){
        auto output = sol.threeSumSmaller(test.input, test.target);
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

