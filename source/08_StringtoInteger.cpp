//LeetCode Problem 8 - String to Integer
#include "everything.h"
using namespace std;
struct Test
{
    string s;
    int sol;
};
class Solution
{
public:
    
    int method1(string s)
    {
        int num = 0;
        bool bNegative = false, bSignFound = false, bNumStart = false;
        for (auto c : s)
        {
            switch (c)
            {
            case ' ':
                if (bNumStart || bSignFound)
                    return num;
                break;
            case '-':
                if(bNumStart)
                    return num;
                if (bSignFound)
                    return 0;
                bSignFound = true;
                bNegative = true;
                break;
            case '+':
                if(bNumStart)
                    return num;
                if (bSignFound)
                    return 0;
                bSignFound = true;
                break;
            default:
                if (c < '0' || c > '9')
                    return num;
                if (!bNegative)
                {
                    if (num > (INT_MAX - int(c - '0')) / 10)
                        return INT_MAX;
                    num = 10 * num + int(c - '0');
                }
                else
                {
                    if (num < (INT_MIN + int(c - '0')) / 10)
                        return INT_MIN;
                    num = 10 * num - int(c - '0');
                }
                bNumStart = true;
            }
        }
        return num;
    }
    int myAtoi(string s)
    {
        return method1(s);
    }
};

int main()
{
    Solution sol;
    vector<Test> vecTests = {
        {.s = "42", .sol = 42},
        {.s = "  -42", .sol = -42},
        {.s = "4193 with words", .sol = 4193},
        {.s = "words and 987", .sol = 0},
        {.s = "-91283472332", .sol = -2147483648},
        {.s = "+-12", .sol = 0},
        {.s = "21474836460", .sol = 2147483647},
        {.s = "-2147483647", .sol = -2147483647},
        {.s = "-2147483649", .sol = -2147483648},
        {.s = "00000-42a1234", .sol = 0},        
        {.s = "-5-", .sol = -5},        
        {.s = "  +  413", .sol = 0},                
        };
    int count = 0;
    for (auto test : vecTests)
    {
        int ret = sol.myAtoi(test.s);
        cout << "Test #" << ++count << " : Input = \"" << test.s << "\", Output = " << ret << ". Result : " << (ret == test.sol ? green : red) << (ret == test.sol ? "Pass" : "Fail") << "!" << def << endl;
    }
    return 0;
}

/*
-----------------------------------------------------------------------------------------------------------
method1: 
use recursion or loop?
Prefer loop

Problem has too many edge cases like "00000-42a1234", "-5-", "  +  413"
Approach is to parse the string and keep flags for finding sign, starting of numbers etc

Remember: datatype limits in C++!!

-----------------------------------------------------------------------------------------------------------
method3: Leetcode Method

-----------------------------------------------------------------------------------------------------------
*/

