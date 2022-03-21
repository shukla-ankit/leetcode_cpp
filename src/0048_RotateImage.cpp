//LeetCode Problem 48 - Rotate Image
/*
-----------------------------------------------------------------------------------------------------------
My Method:

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<vector<int>> input;
    vector<vector<int>> output;
};
class Solution {
    public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n < 2)
            return;
        vector<vector<int>> ret;
        for(int i=0; i < n; i++){
            vector<int> temp;
            for(int j=0; j< n; j++){
                temp.push_back(0);
            }
            ret.push_back(temp);
        }
        for(int i=0; i < n; i++){
            for(int j=0; j< n; j++){
                ret[j][n-1-i] = matrix[i][j];
            }
        }
        matrix = ret;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{{1,2,3},{4,5,6},{7,8,9}}, {{7,4,1},{8,5,2},{9,6,3}}},
            {{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}},{{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        vector<vector<int>> output(test.input);
        sol.rotate(output);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array_of_arrays(test.input) << ", Output = " <<
        print_array_of_arrays(output) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

