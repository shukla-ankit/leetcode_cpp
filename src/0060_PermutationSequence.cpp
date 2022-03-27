//LeetCode Problem 60 - Permutation Sequence
/*
-----------------------------------------------------------------------------------------------------------
Approach 1: This is a very tricky problem!

 The idea is to generate a mapping from 1 to N-1 to lexicographically sorted permutation sequence. Thus using
 only index will allow us to get the permutation at that particular index when ordered lexicographically.

 How to do that? Think of mapping between natual numbers to binary numbers and then use this to represent a
 permutation of say "123". It will be like following:

    0   |   000 |   ""
----------------------------------------------------
    1   |   001 |   "3"
----------------------------------------------------
    2   |   010 |   "2"
----------------------------------------------------
    3   |   011 |   "23"
----------------------------------------------------
    4   |   100 |   "1"
----------------------------------------------------
    5   |   101 |   "13"
----------------------------------------------------
    6   |   110 |   "12"
----------------------------------------------------
    7   |   111 |   "123"

Here, each byte represents the index in sequence [1, 2, 3] and whether we have 1 or 0 decides should that
 number be included.

 But the permutations here aren't lexicographically ordered.
The way it works is as following:
- Think of coefficients of these factorial values as index of the number in array.
- Once you use up that number, you remove it from array before you check index for next number.
For example:

|   Permutation   |   Permutation Number       |Factorial Number System Rep. |
------------------------------------------------------------------------------
|       123       |   0 x 2! + 0 x 1! + 0 x 0! |             000              |   0   |
------------------------------------------------------------------------------
|       132       |   0 x 2! + 1 x 1! + 0 x 0! |             010              |   2   |
------------------------------------------------------------------------------
|       213       |   1 x 2! + 0 x 1! + 0 x 0! |             100              |   4   |
------------------------------------------------------------------------------
|       231       |   1 x 2! + 1 x 1! + 0 x 0! |             110              |   6   |
------------------------------------------------------------------------------
|       312       |   2 x 2! + 0 x 1! + 0 x 0! |             200              |   8   |
------------------------------------------------------------------------------
|       321       |   2 x 2! + 1 x 1! + 0 x 0! |             210              |  10   |
------------------------------------------------------------------------------

where the factorial number system is defined as:
 k = ∑ (m=0 to N−1) km × m!

Therefore magnitude of weights is not constant as well and depends on base: 0≤km≤m0 for the base m!,
 i.e. k0 = 0, 0 ≤ k1 ≤ 1, 0 ≤ k2 ≤ 2, etc.

We can now map all permutations, from permutation number zero:(k=0) = ∑ (m=0 to N−1) 0 × m! to permutation
number: (k=N!−1) = ∑ (m=0 to N−1) m × m!

 -----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    int n;
    int k;
    string output;
};
class Solution {
    public:
    string getPermutation(int n, int k) {
        int factorials[n];
        vector<int> nums = {1};

        factorials[0] = 1;
        for(int i = 1; i < n; ++i) {
            // generate factorial system bases 0!, 1!, ..., (n - 1)!
            factorials[i] = factorials[i - 1] * i;
            // generate nums 1, 2, ..., n
            nums.push_back(i + 1);
        }

        // fit k in the interval 0 ... (n! - 1)
        --k;

        // compute factorial representation of k
        string sb;
        for (int i = n - 1; i >= 0; --i) {
            int idx = k / factorials[i];
            k = k - idx * factorials[i]; // remainder remained

            sb.push_back('0' + nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        return sb;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {3,3,"213"},
            {4,9,"2314"},
            {3,1,"123"}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.getPermutation(test.n, test.k);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : n = " << test.n << ", k = " << test.k << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

