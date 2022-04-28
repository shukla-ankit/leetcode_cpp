//LeetCode Problem 62 - Unique Paths
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    int m;
    int n;
    int output;
};
class Solution {
public:

    //dynamic programming - O(m * n)
    int uniquePaths1(int n_rows, int n_cols) {
        vector<vector<int>> dp(n_rows, vector<int>(n_cols, -1));
        for (int i = n_rows - 1; i > -1; i--) {
            for (int j = n_cols - 1; j > -1; j--) {
                if (i == n_rows - 1 && j == n_cols - 1)
                    dp[i][j] = 1;
                else if (i == n_rows - 1)
                    dp[i][j] = dp[i][j + 1];
                else if (j == n_cols - 1)
                    dp[i][j] = dp[i + 1][j];
                else
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];;
            }
        }
        return dp[0][0];
    }

    //forward backtracking - exponential time complexity
    int backtracking(int cur_x, int cur_y, int goal_x, int goal_y) {
        // Idea is once it reaches rightmost or bottommost column, there is only one way possible
        // terrible time complexity O(2 ^ (m*n))  fixed by using OR instead AND
        if (cur_x == goal_x - 1 || cur_y == goal_y - 1)
            return 1;
        return backtracking(cur_x, cur_y + 1, goal_x, goal_y) + backtracking(cur_x + 1, cur_y, goal_x, goal_y);
    }

    //backward backtracking - exponential time complexity
    int uniquePaths2(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        return uniquePaths2(m - 1, n) + uniquePaths2(m, n - 1);
    }

    int uniquePaths3(int m, int n) { // exponential time complexity
        return backtracking(0, 0, m, n);
    }

    int uniquePaths(int n_rows, int n_cols) {
        return uniquePaths1(n_rows, n_cols);
        return uniquePaths2(n_rows, n_cols);
        return uniquePaths3(n_rows, n_cols);
    };
};

int main() {
    Solution sol;
    vector<Test> vecTests = {
            {3, 7, 28},
            {3, 2, 3},
            {23, 12, 193536720},
            {51,9, 1916797311},
            {1000,1000, 1886677760},
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.uniquePaths1(test.m, test.n);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : m = " << test.m << ", n = " << test.n <<", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
    return 0;
}

