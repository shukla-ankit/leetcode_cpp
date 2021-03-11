//LeetCode Problem 29 - Divide Two Integers    

#include <iostream>
#include <cmath>
#include <cassert>
#include <limits.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor !=0 );
//        assert(dividend >= -pow(2,31));
//        assert(divisor <= pow(2,31)- 1);
        int quotient = 0;
        
        bool bIsQuotNegative = false;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            bIsQuotNegative = true;

        dividend = dividend < 0? dividend: -dividend;
        divisor = divisor < 0? divisor: -divisor;

        while(dividend <= divisor && quotient < INT_MAX){
            dividend -= divisor;
            ++quotient;
        }
        return bIsQuotNegative? -quotient: quotient;
    }
};

int main(){
    Solution s;
    cout << "-2147483648 / 1 = " << s.divide(-2147483648,-1) << endl;
    cout << "-1 / -1 = " << s.divide(-1,-1) << endl;
    cout << "10 / 3 = " << s.divide(10,3) << endl;
    cout << "7 / -3 = " << s.divide(7,-3) << endl;
    cout << "0 / 1 = " << s.divide(0,1) << endl;
    cout << "1 / 1 = " << s.divide(1,1) << endl;

    return 0;
}