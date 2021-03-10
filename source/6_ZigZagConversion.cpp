//LeetCode Problem 6 - ZigZag Conversion

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            string converted;
            for(int i=0; i< s.length(); i+= 2*(numRows -1)){
                converted += s[i];
            }
            for(int i=1; i < numRows-1; i++){
                for(int j=0; j < s.length(); j += 2*(numRows -1)){
                    converted += s[2*(numRows -1) + i];
                    converted += s[2*(numRows -1) - i];
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
                             {"A", 1, "A"}};
    for(auto test: vecTests){
        string res =  sol.convert(test.str,test.rows);
        cout << res << ", matched = " << (res == test.solution? "YES" : "NO") << endl;
    }
	return 0;
}
