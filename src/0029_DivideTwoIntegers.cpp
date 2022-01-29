//LeetCode Problem 29 - Divide Two Integers

/*
-----------------------------------------------------------------------------------------------------------
My Method1:  Time Complexity = O( log n), Space Complexity = O( log n)
    - Create a multiplication table of divisor
    - Convert divisor and dividend both negative for more range, while keep a bool to remember quotient sign
    - Keep subtracting highest multiplication table value from dividend as long as dividend < subtracted value. Once
        condition fails, delete the highest value from multiplication table and do same with next value until table
        is empty. Same time keep incrementing quotient with n_x time value of the table.
    - more important part is not to let any variable overflow
    - return quotient
-----------------------------------------------------------------------------------------------------------
Leetcode Method:
 Approach 1: Repeated Subtraction : Time Complexity = O(n), Space Complexity = O( 1)
 Approach 2: Repeated Exponential Searches : Time Complexity = O( (log n) ^ 2), Space Complexity = O(1)
        - Convert divisor and dividend to negative for more range
        - Two loops:
            Iterate while divisor > dividend (on negative side):
                 Iterate and find maximum multiple of divisor less than dividend and
                  subtract it from dividend and add times to quotient
 Approach 3: Adding Powers of Two : Time Complexity = O(log n), Space Complexity = O( log N)
        - Basically my approach, but two arrays instead of one array of a struct
        - Create table breaks at divisor < HALF_INT_MIN (negative side), so one less condition to check
 Approach 4: Adding Powers of Two with Bit-Shifting : Time Complexity = O(log n), Space Complexity = O(1)
        - Same as Approach 3, except instead of looping over a generated array,
        we simply perform an O(1) halving operation to get the next values we need.
        - Beautiful part is bitwise operations are much faster and no need to store a
        multiplication table!!!
 Approach 5: Binary Long Division :
        It is like dividing a big number with a small number starting from left side
        - Compute max multiple of divisor less than dividend and power of 2 it will be i.e. max_bit
        - Iterate from bit = max_bit to 0
            when adding to quotient, use quotient -= (1 << bit) as power of 2 (quotient negative for more range)
            and halving divisor by divisor = (divisor + 1) >> 1;

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
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)  //because -INT_MIN is outside int range
            return INT_MAX;

        bool bPositive = true;
        if((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0))
            bPositive = false;

        //Converting to negative side as it gives more range
        dividend = dividend < 0 ? dividend: -dividend;
        divisor = divisor < 0? divisor: -divisor;

        int n_divisor = divisor;
        int n_x = -1;  //Converting to negative side as it gives more range
        vector<entry> m;
        m.push_back({n_divisor, n_x});
        while(n_divisor >= dividend && n_divisor >= INT_MIN/2 && n_x >= INT_MIN / 2 ){
            n_divisor = n_divisor + n_divisor;
            n_x = n_x + n_x;
            m.push_back({n_divisor, n_x});
        }
        int quotient = 0;
        while(!m.empty() && dividend != 0){
            if(m[m.size()-1].n_multiple < dividend)
                m.erase(m.begin() + m.size()-1);
            else{
                dividend -= m[m.size()-1].n_multiple;
                quotient += m[m.size()-1].n_x;
            }
        }
        return bPositive? -quotient : quotient;
    }

    int divide3(int dividend, int divisor) {
        int HALF_INT_MIN = -1073741824;

        // Special case: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        std::vector<int> doubles;
        std::vector<int> powersOfTwo;

        /* Nothing too exciting here, we're just making a list of doubles of 1 and
         * the divisor. This is pretty much the same as Approach 2, except we're
         * actually storing the values this time. */
        int powerOfTwo = -1;
        while (divisor >= dividend) {
            doubles.push_back(divisor);
            powersOfTwo.push_back(powerOfTwo);
            // Prevent needless overflows from occurring...
            if (divisor < HALF_INT_MIN) {
                break;
            }
            divisor += divisor;
            powerOfTwo += powerOfTwo;
        }

        int quotient = 0;
        /* Go from largest double to smallest, checking if the current double fits.
         * into the remainder of the dividend */
        for (int i = doubles.size() - 1; i >= 0; i--) {
            if (doubles[i] >= dividend) {
                // If it does fit, add the current powerOfTwo to the quotient.
                quotient += powersOfTwo[i];
                // Update dividend to take into account the bit we've now removed.
                dividend -= doubles[i];
            }
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }

    int divide4(int dividend, int divisor) {
        int HALF_INT_MIN = -1073741824;

        // Special case: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* In the first loop, we simply find the largest double of divisor. This is
        * very similar to the start of what we did in Approach 2.
        * The >= is because we're working in negatives. In essence, that
        * piece of code is checking that we're still nearer to 0 than we
        * are to INT_MIN. */
        int highestDouble = divisor;
        int highestPowerOfTwo = -1;
        while (highestDouble >= HALF_INT_MIN && dividend <= highestDouble + highestDouble) {
            highestPowerOfTwo += highestPowerOfTwo;
            highestDouble += highestDouble;
        }

        /* In the second loop, we work out which powers of two fit in, by
         * halving highestDouble and highestPowerOfTwo repeatedly.
         * We can do this using bit shifting so that we don't break the
         * rules of the question :-) */
        int quotient = 0;
        while (dividend <= divisor) {
            if (dividend <= highestDouble) {
                quotient += highestPowerOfTwo;
                dividend -= highestDouble;
            }
            /* We know that these are always even, so no need to worry about the
             * annoying "bit-shift-odd-negative-number" case. */
            highestPowerOfTwo >>= 1;
            highestDouble >>= 1;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
    int divide5(int dividend, int divisor) {
        int HALF_INT_MIN = -1073741824;
        // Special cases: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        /* We need to convert both numbers to negatives.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* We want to find the largest doubling of the divisor in the negative 32-bit
         * integer range that could fit into the dividend.
         * Note if it would cause an overflow by being less than HALF_INT_MIN,
         * then we just stop as we know double it would not fit into INT_MIN anyway. */
        int maxBit = 0;
        while (divisor >= HALF_INT_MIN && divisor + divisor >= dividend) {
            maxBit += 1;
            divisor += divisor;
        }

        int quotient = 0;
        /* We start from the biggest bit and shift our divisor to the right
         * until we can't shift it any further */
        for (int bit = maxBit; bit >= 0; bit--) {
            /* If the divisor fits into the dividend, then we should set the current
             * bit to 1. We can do this by subtracting a 1 shifted by the appropriate
             * number of bits. */
            if (divisor >= dividend) {
                quotient -= (1 << bit);
                /* Remove the current divisor from the dividend, as we've now
                 * considered this part. */
                dividend -= divisor;
            }
            /* Shift the divisor to the right so that it's in the right place
             * for the next positon we're checking at. */
            divisor = (divisor + 1) >> 1;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            quotient = -quotient;
        }
        return quotient;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.dividend=2147483647, .divisor=3,.output=715827882 },
            {.dividend=1, .divisor=2,.output=0 },
            {.dividend=8, .divisor=2,.output=4 },
            {.dividend=-2147483648, .divisor=-2,.output=1073741824 },
            {.dividend=-2147483647, .divisor=-2,.output=1073741823 },
            {.dividend=2147483647, .divisor=-2,.output=-1073741823 },
            {.dividend=10, .divisor=3,.output=3 },
            {.dividend=7, .divisor=-3,.output=-2 },
            {.dividend=-2147483648, .divisor=1,.output=-2147483648 },
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
