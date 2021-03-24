//LeetCode Problem 35 - Search Insert Position
#include "everything.h"
using namespace std;

struct input{
    vector<int> nums; 
    int target;
};
struct Test{
    struct input Input;
    int Output;
};
class Solution {
    public:
    int bruteforce(vector<int>& nums, int target) {        
        int i =0;
        while(i < nums.size() && nums[i] < target) i++;        
        return i;
    }
    int binarySearch(vector<int>& nums, int start, int end, int target){
        if(target == nums[start]) 
            return start;
        if(end - start <= 1)
            return end;
        
        int mid = (start+end)/2;

        if(target < nums[mid]) return binarySearch(nums, start, mid, target);
        else return binarySearch(nums, mid, end, target);
    }
    int method(vector<int>& nums, int target) {
        //return bruteforce(nums, target);
        int start = 0, end = nums.size() -1;

        if(target < nums[start])
            return 0;
        else if(target > nums[end])
            return end + 1;

        return binarySearch(nums, start, end, target);
    }
    int leetcode_solution(vector<int>& nums, int target) {
        return 0;
    }
    int searchInsert(vector<int>& nums, int target) {
        return method(nums, target);
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {{.Input ={.nums = {1,3,5,6}, .target = 5},.Output=2},
    {.Input= {.nums = {1,3,5,6}, .target = 2},.Output=1},
    {.Input={.nums = {1,3,5,6}, .target = 7}, .Output=4},
    {.Input={.nums = {1,3,5,6}, .target = 0}, .Output= 0},
    {.Input={.nums = {1}, .target = 0},.Output=0}
    };
    int count = 0;
    for(auto test: vecTests){        
        int ret = sol.searchInsert(test.Input.nums, test.Input.target);
        cout << "Test #" << ++count << " : Output = " << ret << ". Result : " <<  (ret == test.Output? green : red) << (ret == test.Output? "Pass" : "Fail") << "!" << def << endl;
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