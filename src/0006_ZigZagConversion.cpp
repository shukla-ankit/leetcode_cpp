//LeetCode Problem 6 - ZigZag Conversion
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
            for (int i=0; i< s.length(); i+= 2*(numRows -1)){
                converted += s[i];
            }
            for (int i = 1; i < numRows-1 && numRows > 2; i++){
                for (int k = 0; k < s.length()/2*(numRows-1); k++){
                    if(s.length() > 2*(numRows-1)* k   + i) 
                        converted += s[ 2*(numRows-1)*k + i ];
                    else
                        break;
                    if(s.length() > 2*(numRows-1)*(k+1)- i) 
                        converted += s[ 2*(numRows-1)*(k+1) - i ];
                    else
                        break;
                }
            }
            for(int i = numRows-1; i < s.length(); i+= 2*(numRows -1)){
                converted += s[i];
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
