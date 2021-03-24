//LeetCode Problem 53 - Maximum Subarray
#include "everything.h"

struct Test{
    vector<int> nums;
    int o;
};
class Solution {
    public:
        int method(vector<int>& nums) {
            return 0;
        }
        int leetcode_solution(vector<int>& nums) {
            return 0;
        }
        int maxSubArray(vector<int>& nums) {
            return method(nums);
        }
};

int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.nums={-2,1,-3,4,-1,2,1,-5,4}, .o=6},
        {.nums={1}, .o=1},
        {.nums={5,4,-1,7,8}, .o=23}
    };
    int count = 0;
    for(auto test: vecTests){        
        int ret = sol.maxSubArray(test.nums);
        cout << "Test #" << ++count << " : Input = " << print_array(test.nums) << ", Output = " << ret << ". Result : " <<  (ret == test.o? green : red) << (ret == test.o? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}
/*
-----------------------------------------------------------------------------------------------------------
method1: <<>>
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/

