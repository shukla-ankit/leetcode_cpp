//LeetCode Problem 6 - ZigZag Conversion
#include "everything.h"
using namespace std;

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
struct Test{
    string str;
    int rows;
    string solution;
};
int main() {
    Solution sol;
    vector<Test> vecTests = {{"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"}, 
                             {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
                             {"A", 1, "A"}
                             };

    for(auto test: vecTests){
        string res =  sol.convert(test.str,test.rows);
        cout << res << ", matched = " << (res == test.solution? "YES" : "NO") << endl;
    }
	return 0;
}
