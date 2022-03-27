//LeetCode Problem 56 - Merge Intervals
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<vector<int>> input;
    vector<vector<int>> output;
};
class Solution {
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y){ return x[0] < y[0];});
        for(int i = 0; i < intervals.size(); i++) {
            if(ret.empty() || ret[ret.size()-1][1] < intervals[i][0])
                ret.push_back(intervals[i]);
            else
                ret[ret.size()-1][1] = ret[ret.size()-1][1] > intervals[i][1] ? ret[ret.size()-1][1] : intervals[i][1];
        }
        return ret;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{{1,3},{2,6},{8,10},{15,18}}, {{1,6},{8,10},{15,18}}},
            {{{1,4},{2,3}}, {{1,4}}},
            {{{1,4},{4,5}}, {{1,5}}}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.merge(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = match_arrays_of_arrays(output, test.output);
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array_of_arrays(test.input) << ", Output = " << print_array_of_arrays(output) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

