//LeetCode Problem 39 - Combination Sum
/*
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

 Backtracking approach-
 1. As candidates will always be > 0, return if target < 0
 2. If target = 0, return current combination of candidates
 3. Iterate over all candidates from current index till end of candidate list
    Keep adding iterated candidate to combination and call backtracking
    Remove added candidate
-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> candidates;
    int target;
    vector<vector<int>> output;
};
class Solution {
    public:
    void backtrack(vector<int>& candidates, int remain, int start, vector<int> &combination, vector<vector<int>> &ret){
        if(remain == 0){
            ret.push_back(combination);
            return;
        }
        else if(remain < 0)
            return;

        for(int i = start; i < candidates.size(); i++){
            combination.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i, combination, ret);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> temp;

        backtrack(candidates, target, 0, temp, ret);
        return ret;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{2,3,6,7}, 7, {{2,2,3},{7}}},
            {{2,3,5}, 8, {{2,2,2,2},{2,3,3},{3,5}}},
            {{2}, 1, {}}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.combinationSum(test.candidates, test.target);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = match_arrays_of_arrays(output, test.output);
        time += duration.count();
        cout << "Test #" << ++count << " : Input : candidates= " << print_array(test.candidates) << ", target=" <<
        test.target << ", Output = " << print_array_of_arrays(output) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<
        (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

