//LeetCode Problem 7 - Reverse Integer
/*
1. Create return variable REV = 0
2. Check sign IsPositive? and get absolute value: N = ABS(N)
3. Iterate over number unless it is ZERO and update REV while taking care of not going beyond INT_MAX
    if (INT_MAX / 10 >= REV && INT_MAX % 10 > N % 10)
        return 0
    else
        REV = 10 * REV + N % 10
    N = N / 10
4. If IsPositive is False, check INT_MIN bound, and retrun -1 * REV
*/

#include "everything.h"
class Solution {
    public:
        string reverseStr(string s){
            string ret;            
            for(int i = s.length() -1; i >-1; i--){
                ret += s[i];
            }
            return ret;
        }
        int method1(int x){
            long u_long_rev_x = x;
            int u_rev_x = 0;
            string str_u_rev_x = reverseStr(to_string(u_long_rev_x < 0? -u_long_rev_x: u_long_rev_x));            
            if(to_string(INT_MAX).length() >= str_u_rev_x.length()){                
                u_long_rev_x = stol(str_u_rev_x);
                if(u_long_rev_x > INT_MIN && u_long_rev_x < INT_MAX){
                    u_rev_x = u_long_rev_x;
                }
            }
            return x < 0? - u_rev_x: u_rev_x;
        }

        int method2(int x){
            int rev_x = 0;
            while(x){
                int m = x%10;
                if((x > 0 && rev_x > (INT_MAX - m)/10) ||
                   (!(x > 0) && rev_x < (INT_MIN - m)/10))
                    return 0;
                rev_x = 10 * rev_x + m;
                x /= 10;
            }
            return rev_x;
        }

        int leetcode_solution(int x) {
            int rev = 0;
            while (x != 0) {
                int pop = x % 10;
                x /= 10;
                if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
                if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
                rev = rev * 10 + pop;
            }
            return rev;
        }

        int reverse(int x) {
            //return method1(x);
            //return method2(x);
            return leetcode_solution(x);
        }
};

struct Test{
    int input;
    int output;
};

int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.input = 123, .output=321}, 
        {.input = -123, .output=-321}, 
        {.input = 120, .output=21}, 
        {.input = 0, .output=0},
        {.input = 1534236469, .output=0},
        {.input =-2147483648, .output=0}
        };
    int count = 0;
    for(auto test: vecTests){
        int ret = sol.reverse(test.input);
        bool bIsPass = ret == test.output;
        cout << "Test #" << ++count << " : Reverse of " << test.input << " is " << ret << ". Result = " << (bIsPass? green : red) << (ret == test.output? "Pass" : "Fail") << def << endl;
    }
	return 0;
}

/*
-----------------------------------------------------------------------------------------------------------
method1: <<EASIER, FASTER WAY>>
Trick1: Convert to string reverse the string

Problem: C++ has limits for datattype
Trick2: use bigger datatypes than required i.e. long instead of int (right from step 2)

step 1: check the sign, keep a flag
step 2: make it positive
step 3: convert to string
step 4: reverse the string
step 5: convert to int
step 6: put the sign and return
-----------------------------------------------------------------------------------------------------------
method2: <<SLIGHTLY DIFFICULT WAY>>

Problem: C++ has limits for datattype
Trick: Check everytime for bounds

Remember1 : climits for INT_MAX and INT_MIN
Remember2 : % operator in C++ gives negative true remainder of division, unlike python complement whatever
Remember2 : DO NOT CONVERT SIGN OF NUMBER! INT_MIN messes it all up!

step 1: Set reverse_x = 0
step 2: Start a loop until x > 0
step 3:     Keep dividing x by 10 and taking out remainder
step 4:     Add remainder to reverse_x as long as in limits. Don't worry about sign of remainder (Remeber 2)
step 5:     if limits fair, return 0
step 6: When loop ends, return reverse_x
-----------------------------------------------------------------------------------------------------------
method3: Leetcode Method
Problem: C++ has limits for datattype
Trick: Memorize unit's place digits for limits. Makes it easier than condition checks in method2

Remember 4: Memorize INT_MAX has 7 at unit's place and INT_MIN has -8 (Remember 2 from method2)
Approach is same as method2
-----------------------------------------------------------------------------------------------------------
*/