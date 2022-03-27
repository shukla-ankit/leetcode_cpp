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
    int backtracking(int cur_x, int cur_y, int goal_x, int goal_y){
        //forward backtracking
        // Idea is once it reaches rightmost or bottommost column, there is only one way possible
        if( cur_x == goal_x - 1 || cur_y == goal_y - 1)
            return 1;
        return backtracking(cur_x, cur_y + 1, goal_x, goal_y) + backtracking(cur_x + 1, cur_y, goal_x, goal_y);
    }

    int uniquePaths2(int m, int n) { //backward backtracking
        if(m == 1 || n == 1)
            return 1;
        return uniquePaths2(m - 1, n) + uniquePaths2(m, n-1);
    }

    int uniquePaths(int m, int n) {
        return backtracking(0, 0, m, n); // terrible time complexity O(2 ^ (m*n))
        //return uniquePaths2(m, n);
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {3, 7, 28},
            {3, 2, 3},
            {23, 12, 193536720}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.uniquePaths(test.m, test.n);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : m = " << test.m << ", n = " << test.n <<", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

