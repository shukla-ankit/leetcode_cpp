//LeetCode Problem 55 - Jump Game
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> input;
    bool output;
};
class Solution {
    public:
    bool canJump(vector<int>& nums) {
        int current = 0, curMaxJump = nums[0], nextMaxJump = nums[0], numJumps = 0;
        for(int i=current; i <= curMaxJump; i++){
            if(nextMaxJump >= nums.size() - 1)
                return true;
            nextMaxJump = max(nextMaxJump, i + nums[i]);
            if(i == curMaxJump)
                curMaxJump = nextMaxJump;
        }
        return false;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{1,2,3}, true},
            {{2,3,1,1,4}, true},
            {{3,2,1,0,4}, false}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.canJump(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

