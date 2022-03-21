//LeetCode Problem 50 - Pow_x_n
/*
-----------------------------------------------------------------------------------------------------------
My Method:

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    double x;
    int n;
    double output;
};
class Solution {
    public:
    double myPow(double x, int n) {
        //cout << x << " " << n << endl;
        if(x == 0.0)
            return 0.0;
        if(n < 0){
            if(n == INT_MIN)
                return 1.0/(x * myPow(x, INT_MAX));
            else
                return 1.0 / myPow(x, -n);
        }
        if(abs(x) == 1)
            return x < 0 && n % 2 == 0 ? -x : x;
        if(n == 0)
            return 1.0;

        return n % 2 == 0? myPow(x * x, n / 2) : x * myPow(x * x, (n - 1) / 2) ;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {2.00000, 10, 1024.00000},
            {2.10000, 3, 9.261},
            {2.00000, -2, 0.25000},
            {1.00000, -2147483648, 1.00000},
            {2.00000, -2147483648, 0.00000},
            {0.00001, 2147483647, 0.00000},
            {-1.00000, 2147483647, -1},
            {0.44528,0, 1.00000},
            {2.00000, -2, 0.25}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.myPow(test.x, test.n);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input : x=" << test.x << ", n=" << test.n << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

