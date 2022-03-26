//LeetCode Problem 45 - Jump Game II
/*
-----------------------------------------------------------------------------------------------------------
Approach 1: Backtracking
    Time Complexity : Horrible!


Approach 2: Greedy approach
    Time Complexity : O(n)
-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> input;
    int output;
};
class Solution {
    public:
//my approach
    int jump(vector<int>& nums) {
        int current = 0, curMaxJump = nums[0], nextMaxJump = nums[0], numJumps = 0;
        if(nums.size() > 1)
            ++numJumps;
        for(int i=current; i <= curMaxJump; i++){
            if(i >= nums.size() - 1)
                return numJumps;
            nextMaxJump = max(nextMaxJump, i + nums[i]);
            if(i == curMaxJump){
                curMaxJump = nextMaxJump;
                ++numJumps;
            }
        }
        return -1;
    }

//approach 1
    void backtracking(vector<int>& nums, int start, int total_jumps, int& min_jumps){
        if(min_jumps < total_jumps)
            return;
        if(start == nums.size()-1 && min_jumps > total_jumps)
            min_jumps = total_jumps;
        if(start < nums.size()-1){
            for(int i=nums[start]; i >=1 ; i--){ //Preferring longer jumps
                //cout << start+i << "," << jumps + 1 << "," <<  min_jumps << endl;
                backtracking(nums, start+i, total_jumps + 1, min_jumps);
            }
        }
    }

    int jump1(vector<int>& nums) {
        int jumps = 0, min_jumps = INT_MAX;
        backtracking(nums, 0, jumps, min_jumps);
        return min_jumps;
    }
//approach 2
    int jump2(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int curMax = 0; // to mark the last element in a level
        int level = 0, i = 0;
        while (i <= curMax) {
            int furthest = curMax; // to mark the last element in the next level
            for (; i <= curMax; i++) {
                furthest = max(furthest, nums[i] + i);
                if (furthest >= nums.size() - 1) return level + 1;
            }
            level++;
            curMax = furthest;
        }
        return -1; // if i < curMax, i can't move forward anymore (the last element in the array can't be reached)
    }

    int jump(vector<int>& nums){
        //return jump1(nums);
        return jump2(nums);
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{2,3,1,1,4}, 2},
            {{5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5},5},
            {{8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5}, 13},
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.jump(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

