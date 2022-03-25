//LeetCode Problem 51 - N-Queens
/*
-----------------------------------------------------------------------------------------------------------
Leetcode Method:
Approach - Backtracking:
    1. Create a 2D vector - board with ',' as each cell value, a vector of 2D vectors - ret, set of columns, set of diagonals, set of antidiagonals
    and pass them to backtracking method as reference
    2. if row == size of maze, return ret
       else
       iterate col from 0 to size
            If current column already exists in set of columns or current diagonal exists in set of current
            diagonals or current anti-diagonal exists in set of anti-diagonals, continue to next interation
            Else,
                board[row][col] = 'Q'
                cols.insert(col)
                diagonals.insert(cur_diagonal), where cur_diagonal = row - col
                antidiagonals.insert(cur_antidiagonals), where cur_diagonal = row + col
                backtracking(row + 1, board, ret, cols, diagonals, antidiagonals)
                board[row][col] = '.'
                cols.erase(col)
                diagonals.erase(cur_diagonal)
                antidiagonals.erase(cur_antidiagonals)

 Diagonals: row - col  can be used to identify diagonal elements

        0   |   -1    |   -2    |   -3    |   -4    |   -5
    -----------------------------------------------------------
        1   |    0    |   -1    |   -2    |   -3    |   -4
    -----------------------------------------------------------
        2   |    1    |    0    |   -1    |   -2    |   -3
    -----------------------------------------------------------
        3   |    2    |    1    |    0    |   -1    |   -2
    -----------------------------------------------------------
        4   |    3    |    2    |    1    |    0    |   -1
    -----------------------------------------------------------
        5   |    4    |    3    |    2    |    1    |    0

 Anti-diagonal: row + col can be used to identify antidiagonal elements

        0   |    1    |    2    |    3    |    4    |    5
    -----------------------------------------------------------
        1   |    2    |    3    |    4    |    5    |    6
    -----------------------------------------------------------
        2   |    3    |    4    |    5   |     6    |    7
    -----------------------------------------------------------
        3   |    4    |    5   |     6    |    7    |    8
    -----------------------------------------------------------
        4   |    5   |     6    |    7    |    8    |    9
    -----------------------------------------------------------
        5   |    6    |    7    |    8    |    9    |    10

 -----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    int input;
    vector<vector<string>> output;
};
class Solution {
    public:
    void backtrack(int size, vector<vector<string>> &ret, vector<string> &board, int row, set<int> &cols, set<int> &diagonals, set<int> &antidiagonals){
        if(row == size){
            ret.push_back(board);
            return;
        }
        for(int col = 0; col < size; col++){
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            if(cols.find(col) != cols.end() || diagonals.find(currDiagonal) != diagonals.end() || antidiagonals.find(currAntiDiagonal) != antidiagonals.end())
                continue;

            cols.insert(col);
            diagonals.insert(currDiagonal);
            antidiagonals.insert(currAntiDiagonal);
            board[row][col] = 'Q';

            backtrack(size, ret, board, row + 1, cols, diagonals, antidiagonals);

            cols.erase(col);
            diagonals.erase(currDiagonal);
            antidiagonals.erase(currAntiDiagonal);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> board(n, string(n, '.'));
        set<int> cols, diagonals, antidiagonals;
        backtrack(n, ret, board, 0, cols, diagonals, antidiagonals);
        return ret;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {4, {{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}}},
            {1, {{"Q"}}}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.solveNQueens(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = match_arrays_of_arrays(output, test.output);
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << test.input << ", Output = " << print_array_of_arrays(output) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

