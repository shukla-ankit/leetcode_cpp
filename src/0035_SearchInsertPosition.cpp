//LeetCode Problem 35 - Search Insert Position
/*
    Approach 1: Binary search problem
    1. left = 0, right = nums.size() -1
    2. Iterate with condition that left < right always
        - compute mid = (left + right) / 2;
        - if nums[mid] == target, return mid. Good for an insert position
        - Otherwise,
        - if nums[mid] < target, right = mid - 1. Else left = mid + 1
    3. When condition fails i.e. left == right, compare nums[left] with target
    4. if nums[left] < target, return left + 1 as insert position. Else left.

 -----------------------------------------------------------------
 Binary search problem.
Only change - Asks insert index if searched number not found.

start with finding mid = (start + end)/2
if nums[mid] = target, return mid
else change start or end depending on where target falls

if start > end, return start as insertion index <<<-------- This part I struggled to understand.
The reason is initially "start <= end" condition held true, the number was in this interval.
Later start and end must have become equal.
After that, either
1. start was increased, which means : searched number is greater than mid = start = end and needs to be inserted right after start, which is also end.
2. end was decreased, which means searched number is less than nums[mid], when mid = start = mid, So searched number needs to be inserted at start 
and moving every number after it to right by 1.

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

    int searchInsert1(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;

        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;

            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if(target > nums[left])
            return left + 1;
        return left;
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
        //return method(nums, target);
        return searchInsert1(nums, target);
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
