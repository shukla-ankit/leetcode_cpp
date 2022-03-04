//LeetCode Problem 37 - Sudoku Solver
/*
-----------------------------------------------------------------------------------------------------------
My Method:

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<vector<char>> input;
    vector<vector<char>> output;
};
class Solution {
    public:
    const int n = 3, N = n*n;
    bool isSolved = false;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<int>> cells;

    bool isAllowed(char n, int r, int c){
        return rows[r][n - '1'] + cols[c][n - '1'] + cells[3 * (r / 3) + (c/3) ][n- '1'] == 0;
    }

    void put(vector<vector<char>> &board, char n, int r, int c){
        board[r][c] = n;
        rows[r][n-'1']++;
        cols[c][n-'1']++;
        cells[3 * (r / 3) + (c/3)][n-'1']++;
    }

    void remove(vector<vector<char>> &board, char n, int r, int c){
        board[r][c] = '.';
        rows[r][n-'1']--;
        cols[c][n-'1']--;
        cells[3 * (r / 3) + (c/3)][n-'1']--;
    }

    void placeNext(vector<vector<char>> &board, int row, int col){
        if(row == N-1 && col == N-1)
            isSolved=true;
        else{
            if(col == N-1)
                backtracking(board, row+1, 0);
            else
                backtracking(board, row, col+1);
        }
    }

    void backtracking(vector<vector<char>>& board, int row, int col){
        if(board[row][col] == '.'){
            for(int d=1;d<=9;d++){
                if(isAllowed('0'+d, row, col)){
                    put(board, '0'+d, row, col);
                    placeNext(board, row, col);
                    if(!isSolved)
                        remove(board, '0'+d, row, col);
                }
            }
        }
        else
            placeNext(board, row, col);
    }

    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(N, vector<int>(N, 0));
        cols.resize(N, vector<int>(N, 0));
        cells.resize(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++){
            for(int j=0; j<N; j++){
                if(board[i][j] != '.'){
                    rows[i][board[i][j]-'1']++;
                    cols[j][board[i][j]-'1']++;
                    cells[(i/3)*3+(j/3)][board[i][j]-'1']++;
                }
            }
        }
        backtracking(board, 0,0);
        return;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            { {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}}, {{'5','3','4','6','7','8','9','1','2'},{'6','7','2','1','9','5','3','4','8'},{'1','9','8','3','4','2','5','6','7'},{'8','5','9','7','6','1','4','2','3'},{'4','2','6','8','5','3','7','9','1'},{'7','1','3','9','2','4','8','5','6'},{'9','6','1','5','3','7','2','8','4'},{'2','8','7','4','1','9','6','3','5'},{'3','4','5','2','8','6','1','7','9'}}},
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        vector<vector<char>> output(test.input);
        sol.solveSudoku(output);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = match_arrays_of_arrays(output,test.output);
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array_of_arrays<char>(test.input) << ",\n\tOutput = " << print_array_of_arrays<char>(output) << ",\n\tTime taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

