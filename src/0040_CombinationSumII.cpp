//LeetCode Problem 40 - Combination Sum II
/*
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

 Using backtracking. Instead of list of candidates, pass the frequency counter list (not map, as it is not possible
 to iterate)
-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> candidates;
    int target;
    vector<vector<int>> output;
};

struct FreqCounter{
    int num;
    int frequency;
};
class Solution {
public:
    void backtracking(vector<FreqCounter> &vecFreqCounter, int remain, int current, vector<int> &comb, vector<vector<int>> &result){
        if(remain <= 0){
            if(remain == 0)
                result.push_back(comb);
            return;
        }
        for(auto i = current; i < vecFreqCounter.size(); i++){
            comb.push_back(vecFreqCounter[i].num);
            vecFreqCounter[i].frequency--;
            if(vecFreqCounter[current].frequency >= 0)
                backtracking(vecFreqCounter, remain - vecFreqCounter[i].num, i, comb, result);
            vecFreqCounter[i].frequency++;
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;

        sort(candidates.begin(), candidates.end());
        vector<FreqCounter> vecFreqCounter;
        int prev = -1, count = 0;
        for(int i = 0; i < candidates.size(); i++){
            if(prev != candidates[i]) {
                if(prev != -1)
                    vecFreqCounter.push_back({prev, count});
                count = 0;
                prev = candidates[i];
            }
            count++;
        };
        if(prev != -1 && count > 0)
            vecFreqCounter.push_back({prev, count});

        backtracking(vecFreqCounter, target, 0, comb, res);
        return res;
    }


};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{10,1,2,7,6,1,5}, 8, {{1,1,6},{1,2,5},{1,7},{2,6}}},
            {{2,5,2,1,2}, 5, {{1,2,2},{5}}},
            {{2}, 1, {}},
            {{10,1,2,7,6,1,5}, 8, {{1,7},{1,1,6},{1,2,5}, {2,6}}},
            {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
              1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            30,{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.combinationSum2(test.candidates, test.target);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = equal(output.begin(), output.end(), test.output.begin());
        time += duration.count();
        cout << "Test #" << ++count << " : Input : candidates= " << print_array(test.candidates) << ", target=" <<
             test.target << ", Output = " << print_array_of_arrays(output) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<
             (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
    return 0;
}

