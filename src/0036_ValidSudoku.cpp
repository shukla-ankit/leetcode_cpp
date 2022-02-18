//LeetCode Problem 36 - Valid Sudoku
/*
-----------------------------------------------------------------------------------------------------------
My Method:
1. Parse each row and then each column and check if there is a repeated character. If yes, then return false, else true
2. Also, check each cell. Use two loops for cells and then two loops for numbers inside cell. Same approach as above,
 except checking across rows and columns in the cell.
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"
struct Test{
    vector<vector<char>> input;
    bool output;
};
class Solution {
public:
    bool check(vector<vector<char>>& board, bool bCheckRows = true){
        for(int i = 0; i < board.size(); i++){
            unordered_set<char> s;
            for(int j = 0; j < board[0].size(); j++){
                if(bCheckRows){
                    if(('1' <= board[i][j] && board[i][j] <= '9' && s.find(board[i][j]) == s.end()) || board[i][j] == '.')
                        s.insert(board[i][j]);
                    else
                        return false;
                }
                else{
                    if(('1' <= board[j][i] && board[j][i] <= '9' && s.find(board[j][i]) == s.end()) || board[j][i] == '.')
                        s.insert(board[j][i]);
                    else
                        return false;
                }
            }
            s.clear();
        }
        return true;
    }

    bool checkGrid(vector<vector<char>>& board){
        for(int i = 0; i < board[0].size()/3; i++){
            for(int j = 0; j < board.size()/3; j++){
                unordered_set<char> s;
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(('1' <= board[3*i + k][3*j + l] && board[3*i + k][3*j + l] <= '9' && s.find(board[3*i + k][3*j + l]) == s.end()) || board[3*i + k][3*j + l] == '.')
                            s.insert(board[3*i + k][3*j + l]);
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return check(board, true) &&
               check(board, false) &&
               checkGrid(board);
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}}, true},
            {{{'8','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}}, false},
            {{{'5','3','.','.','7','.','.','.','.'},{'3','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}}, false},
            {{{'5','3','.','.','7','.','.','.','.'},{'6','3','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}}, false}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.isValidSudoku(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array_of_arrays(test.input) << ",\n\tOutput = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

