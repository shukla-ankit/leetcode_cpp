//LeetCode Problem 6 - ZigZag Conversion
/*
1. When creating a zigzag pattern with S string and N rows
2. Begin from 0th row by adding every (2N-1)th character starting from 0 
3. Iterate over rows from 1 to n -2, and then iterate over repeat index k

    going down added char will be s[ 2*(N-1)*repeat_idx + row_idx ];
    coming up string char be s[ 2*(N-1)*(repeat_idx+1) - row_idx]

    Break the loop when indices exceed the length of the string
6. Lastly for (n-1)th row, add every (2N-1)th character starting from N-1
*/

#include "everything.h"
struct input{
    string text;
    int rows;
};
struct Test{
    input Input;
    string Output;
};
class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows == 1) return s;
            string converted;            
            for (int row_idx=0; row_idx< s.length(); row_idx+= 2*(numRows -1)){
                converted += s[row_idx];
            }
            for (int row_idx = 1; row_idx < numRows-1; row_idx++){
                for (int k = 0; k < s.length()/2*(numRows-1); k++){
                    if(s.length() > 2*(numRows-1)* k   + row_idx) 
                        converted += s[ 2*(numRows-1)*k + row_idx ];
                    else
                        break;
                    if(s.length() > 2*(numRows-1)*(k+1)- row_idx) 
                        converted += s[ 2*(numRows-1)*(k+1) - row_idx ];
                    else
                        break;
                }
            }
            for(int row_idx = numRows-1; row_idx < s.length(); row_idx+= 2*(numRows -1)){
                converted += s[row_idx];
            }
            return converted;
        }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.Input={.text="PAYPALISHIRING", .rows=3},.Output="PAHNAPLSIIGYIR"},
    	{.Input={.text="PAYPALISHIRING",.rows=4},.Output="PINALSIGYAHRPI"},
        {.Input={.text="A",.rows=1},.Output="A"}
    };    
    int count = 0;
    for(auto test: vecTests){        
        string ret = sol.convert(test.Input.text, test.Input.rows);
		bool bIsPass = ret == test.Output;
        cout << "Test #" << ++count << " : Input { " << test.Input.text << " , " <<test.Input.rows << "}, Output = " << ret << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}
