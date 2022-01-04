//LeetCode Problem 46 - Permutations
#include "everything.h"

struct Test{
    vector<int> input;
    vector<vector<int>> output;
};
class Solution {
    public:
        void swap(vector<int>& myvec, int a, int b){
            if( a >= 0 && b >= 0 && a < myvec.size() && b < myvec.size())
            {
                int t = myvec[a];
                myvec[a] = myvec[b];
                myvec[b] = t;
            }
        }
        void backtrack(int n,
                                vector<int> &nums,
                                vector<vector<int>> &output,
                                int first) {
            // if all integers are used up
            if (first == n)
            output.push_back({nums});
            for (int i = first; i < n; i++) {
            // place i-th integer first 
            // in the current permutation
            swap(nums, first, i); 
            // use next integers to complete the permutations
            backtrack(n, nums, output, first + 1);
            // backtrack
            swap(nums, first, i);
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ret;
            vector<int> temp = nums;
            backtrack(nums.size(), nums, ret, 0);
            return ret;
        }

        vector<vector<int>> method(vector<int>& nums){
            return permute(nums);
        }
        vector<vector<int>> leetcode_solution(vector<int>& nums){
            return {};
        }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
                                {.input={1,2,3},.output={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}},
                                {.input={0,1},.output={{0,1},{1,0}}},
                                {.input={1},.output={{1}}},
                            };
    int count = 0;
    for(auto test: vecTests){
        vector<vector<int>> output = sol.method(test.input);
        bool bIsPass = match_arrays_of_arrays<int>(test.output, output);
        if(bIsPass)
            cout << "Test #" << ++count << " : Input = " << print_array<int>(test.input) << ", Output = " << print_array_of_arrays<int>(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
        else
            cout << "Test #" << ++count << " : Input = " << print_array<int>(test.input) << ", Output = " << print_array_of_arrays<int>(output) << ", Expected = " << print_array_of_arrays<int>(test.output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

