//LeetCode Problem 238 - Product of Array Except Self
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> input;
    vector<int> output;
};
class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long product = 1;
        int countZeros = 0;
        for(int n : nums) {
            if (n != 0)
                product *= n;
            else
                countZeros++;
        }
        vector<int> ret;
        for(int n : nums){
            if(countZeros){
                if(countZeros == 1)
                    ret.push_back(n == 0? product : 0);
                else
                    ret.push_back(0);
            }
            else
                ret.push_back(product / n);
        }
        return ret;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.input={1,2,3,4}, .output={24,12,8,6}},
            {.input={-1,1,0,-3,3}, .output={0,0,9,0,0}}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.productExceptSelf(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = match_array(output, test.output);
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " << print_array(output) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

