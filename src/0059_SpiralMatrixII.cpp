//LeetCode Problem 59 - Spiral Matrix II
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:
1. Create a loop variable, a direction enum and counter
2. Loop will change direction when
    - RIGHT -> DOWN : row == nrows - 1 - loop,  where outermost loop starts from 0
    - DOWN -> LEFT : col == ncols - 1 - loop
    - LEFT -> UP: col == loop
    - UP -> RIGHT: row == loop + 1
3. When direction changes,
    - RIGHT : col++
    - DOWN: row++
    - LEFT : col--
    - UP : row--
    Keep incrementing counter and assigning it to matrix[row][col]
With direction change, increments in row and column need be made as per new direction.
-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    int input;
    vector<vector<int>> output;
};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> matrix;
        if(n > 0)
        {
            matrix.resize(n, vector<int>(n, INT_MIN));
            enum Direction{ RIGHT, DOWN, LEFT, UP};
            Direction currDirection = Direction::RIGHT;
            int row = 0, col = 0, n_rows = n, n_cols = n, loop = 0, current = 0;
            while(current < n_rows * n_cols){
                matrix[row][col] = ++current;
                if(currDirection == Direction::RIGHT){
                    if(col == n_cols - 1  - loop) {
                        currDirection = Direction::DOWN;
                        row++;
                    }
                    else
                        col++;
                }
                else if(currDirection == Direction::DOWN){
                    if(row == n_rows - loop - 1) {
                        currDirection = Direction::LEFT;
                        col--;
                    }
                    else
                        row++;
                }
                else if(currDirection == Direction::LEFT){
                    if(col == loop) {
                        currDirection = Direction::UP;
                        row--;
                    }
                    else
                        col--;
                }
                else if(currDirection == Direction::UP){
                    if(row == loop + 1){
                        currDirection = Direction::RIGHT;
                        loop++;
                        col++;
                    }
                    else
                        row--;
                }
            }
        }
        return matrix;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {3, {{1,2,3},{8,9,4},{7,6,5}}},
            {1,{{1}}}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.generateMatrix(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = match_arrays_of_arrays(output, test.output);
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << (test.input) << ", Output = " << print_array_of_arrays(output) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
    return 0;
}

