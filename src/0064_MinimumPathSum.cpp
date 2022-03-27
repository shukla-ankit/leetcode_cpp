//LeetCode Problem 64 - Minimum Path Sum
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<vector<int>> input;
    int output;
};
class Solution {
    public:
    int minPathSum(vector<vector<int>>& grid) {
        int nrows = grid.size(), ncols = grid[0].size();
        vector<vector<int>> dp;
        dp.resize(nrows, vector<int>(ncols, INT_MAX));

        for(int i = nrows - 1; i >=0; i--){
            for(int j = ncols - 1; j >=0; j--){
                if(i == nrows -1 && j != ncols -1)
                    dp[i][j] = grid[i][j] + dp[i][j+1];
                else  if(i != nrows -1 && j == ncols -1)
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                else  if(i != nrows -1  && j != ncols -1)
                    dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
                else
                    dp[i][j] = grid[i][j];
            }
        }
        return dp[0][0];
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{{1,3,1},{1,5,1},{4,2,1}}, 7},
            {{{1,2,3},{4,5,6}}, 12}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.minPathSum(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array_of_arrays(test.input) << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

