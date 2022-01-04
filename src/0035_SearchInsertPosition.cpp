//LeetCode Problem 35 - Search Insert Position
/*
Binary search problem. 
Only change - Asks insert index if searched number not found.

start with finding mid = (start + end)/2
if nums[mid] = target, return mid
else change start or end depending on where target falls

if start > end, return start as insertion index <<<-------- This part I struggled to understand.
The reason is when "start < end" condition failed, the number was in this interval.

Earlier start and end must have been equal.

So if start was increased, it means searched number needs to be inserted right after end, which is start.

Otherwise If end was decreased further it means searched number is less than nums[mid], when mid = start = mid.
So searched number needs to be inserted at start and moving every number after it to right by 1.
*/

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

     int binarySearch_recursive(vector<int>& nums, int start, int end, int target){
        if(start > end) return start;        
        
        int mid = (start+end)/2;
        
        cout << "start = " << start << ", mid =" << mid << ", end = " << end << endl;

        if(target == nums[mid])
            return mid;
        else if(target < nums[mid]) 
            return binarySearch_recursive(nums, start, mid - 1, target);
        else 
            return binarySearch_recursive(nums, mid + 1, end, target);
    }

    int binarySearch_non_recursive(vector<int>& nums, int target) {
        int start = 0, end = nums.size() -1;
        while(start <= end){
            int mid = (start + end)/2;
            //cout << "start = " << start << ", mid =" << mid << ", end = " << end << endl;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                start = mid + 1;
            else if( nums[mid] > target)
                end = mid - 1;
        }
        return start;
    }
    int method(vector<int>& nums, int target) {
        //return bruteforce(nums, target);
        int start = 0, end = nums.size() -1;

        if(target < nums[start])
            return 0;
        else if(target > nums[end])
            return end + 1;

        return binarySearch_recursive(nums, start, end, target);
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
        cout << "Test #" << ++count << " : Input = {" << print_array(test.Input.nums) << " , " << test.Input.target<< "}, Output = " << ret << ". Result : " <<  (ret == test.Output? green : red) << (ret == test.Output? "Pass" : "Fail") << "!" << def << endl;
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