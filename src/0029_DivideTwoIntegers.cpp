//LeetCode Problem 29 - Divide Two Integers

/*
-----------------------------------------------------------------------------------------------------------
My Method1:
    - Create a multiplication table of divisor
    - Convert divisor and dividend both negative, while keep a bool to remember quotient sign
    - Keep subtracting highest multiplication table value from dividend as long as dividend < subtracted value. Once
        condition fails, delete the highest value from multiplication table and do same with next value until table
        is empty. Same time keep incrementing quotient with n_x time value of the table.
    - return quotient
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/


#include "everything.h"

struct Test{
    int dividend;
    int divisor;
    int output;
};

struct entry{
    int n_multiple;
    int n_x;
};

class Solution {
    public:
    int divide1(int dividend, int divisor){ // O(log n)
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool bPositive = true;
        if((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0))
            bPositive = false;
        dividend = dividend < 0 ? dividend: -dividend;
        divisor = divisor < 0? divisor: -divisor;

        int quotient = 0;
        while(dividend <= divisor){
            dividend -= divisor;
            quotient++;
        }
        return bPositive? quotient: -quotient;
    }

    int divide(int dividend, int divisor){ // O(log n)
        bool bPositive = true;
        if((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0))
            bPositive = false;

        if(abs(divisor) == 1)
            return divisor > 0? dividend: -dividend;

        dividend = dividend < 0 ? dividend: -dividend;
        divisor = divisor < 0? divisor: -divisor;

        int n_divisor = divisor;
        int n_x = 1;
        vector<entry> m;
        while(n_divisor >= dividend && - 2 * n_x > INT_MIN){    //condition
            m.push_back({n_divisor, n_x});
            n_divisor = n_divisor + n_divisor;
            n_x = n_x + n_x;
        }
        int quotient = 0;
        n_divisor = m[m.size()-1].n_multiple;

        while(!m.empty()){ //condition
            if(m[m.size()-1].n_multiple >= dividend){   //condition
                dividend -= m[m.size()-1].n_multiple;
                quotient += m[m.size()-1].n_x;
            }
            else
                m.erase(m.begin() + m.size()-1);
        }
        return bPositive? quotient : -quotient;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.dividend=8, .divisor=2,.output=4 },
            {.dividend=-2147483648, .divisor=-2,.output=1073741824 },
            {.dividend=-2147483647, .divisor=-2,.output=1073741823 },
            {.dividend=2147483647, .divisor=-2,.output=-1073741823 },
            {.dividend=-2147483648, .divisor=1,.output=-2147483648 },
            {.dividend=10, .divisor=3,.output=3 },
            {.dividend=7, .divisor=-3,.output=-2 },
    };
    int count = 0;
    for(auto test: vecTests){
        auto output = sol.divide(test.dividend, test.divisor);
        bool bIsPass = output == test.output;
        cout << "Test #" << ++count << " : Dividend=" << test.dividend << ", Divisor=" << test.divisor <<
        ", Output = " << output << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") <<
        "!" << def << endl;
    }
	return 0;
}
