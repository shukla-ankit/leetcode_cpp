//LeetCode Problem 47 - Permutations II
/*
-----------------------------------------------------------------------------------------------------------
My Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> input;
    vector<vector<int>> output;
};
class Solution {
    public:
    void swap(vector<int>& nums, int x, int y){
        if(x < 0  || y < 0 || x >= nums.size() || y >= nums.size()){
            cout << "Index out of vector array bound." << endl;
            return;
        }
        int k = nums[x];
        nums[x] = nums[y];
        nums[y] = k;
    }
    void back_tracking(vector<int>& nums, set<vector<int>>& permutations, int first, int last){
        if(first == last){
            permutations.insert({nums});
            return;
        }
        for(int i = first; i < last; i++){
            swap(nums, first, i);
            back_tracking(nums, permutations, first+1, last);
            swap(nums, first, i);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp = nums;
        vector<vector<int>> permutations;
        set<vector<int>> s_permutations;
        back_tracking(temp, s_permutations, 0, temp.size());
        for(auto e : s_permutations){
            permutations.push_back(e);
        }
        return permutations;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{1,1,2}, {{1,1,2},{1,2,1},{2,1,1}}},
            {{1,2,3}, {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.permuteUnique(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " << print_array_of_arrays(output) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

