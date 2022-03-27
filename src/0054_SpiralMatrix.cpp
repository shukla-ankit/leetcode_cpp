//LeetCode Problem 54 - Spiral Matrix
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<vector<int>> input;
    vector<int> output;
};
class Solution {
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(!matrix.empty()){
            int rows = matrix.size(), cols = matrix[0].size(), loop = 0;
            enum Direction{ RIGHT, DOWN, LEFT, UP};
            Direction currDirection = Direction::RIGHT;
            int row = 0, col = 0;
            while(ret.size() < rows * cols){
                ret.push_back(matrix[row][col]);
                if(currDirection == Direction::RIGHT){
                    col++;
                    if(col == cols - loop) {
                        currDirection = Direction::DOWN;
                        col = cols - loop - 1;
                        row++;
                    }
                }
                else if(currDirection == Direction::DOWN){
                    row++;
                    if(row == rows - loop){
                        row = rows - loop - 1;
                        currDirection = Direction::LEFT;
                        col--;
                    }
                }
                else if(currDirection == Direction::LEFT){
                    col--;
                    if(col == loop-1) {
                        currDirection = Direction::UP;
                        col = loop;
                        row--;
                    }
                }
                else if(currDirection == Direction::UP){
                    if(row == loop + 1){
                        loop++;
                        col++;
                        currDirection = Direction::RIGHT;
                    }
                    else
                        row--;
                }
            }
        }
        return ret;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{{1,2,3},{4,5,6},{7,8,9}},{1,2,3,6,9,8,7,4,5}},
            {{{1,2,3,4},{5,6,7,8},{9,10,11,12}}, {1,2,3,4,8,12,11,10,9,5,6,7}},
            {{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}}, {1,2,3,4,5,10,15,20,25,24,23,22,21,16,11,6,7,8,9,14,19,18,17,12,13} }
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.spiralOrder(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = match_array(output, test.output);
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array_of_arrays(test.input) << ", Output = " << print_array(output) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

