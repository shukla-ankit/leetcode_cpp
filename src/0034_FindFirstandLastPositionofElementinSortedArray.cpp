//LeetCode Problem 34 - Find First and Last Position of Element in Sorted Array
/*
-----------------------------------------------------------------------------------------------------------
Leetcode Method:
Approach 1.
    1. Search for start and end index separately.
    2. If start index not found, return {-1, -1} as target wasn't found.
    3. In binary search, if nums[mid] < target, left = mid + 1 and if nums[mid] > target, right = mid -1
       Important part is when nums[mid] == target.
       Then,
       - if looking for start index, if mid == left or nums[mid-1] != target, return mid.
        Else right = mid - 1
       - if looking for end index, if mid == right or nums[mid+1] != target, return mid.
        Else left = mid + 1

    This gives O(log n) time complexity.

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> nums;
    int target;
    vector<int> output;
};
class Solution {
public:
    int binary_search(vector<int>& nums, int target, bool searchingStart){
        int left = 0, right = nums.size() - 1, start = left, end = right;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
            else{
                if(searchingStart){
                    if(mid == left || nums[mid-1] != target)
                        return mid;
                    right = mid - 1;
                }
                else{
                    if(mid == right || nums[mid + 1] != target)
                        return mid;
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = binary_search(nums, target, true);
        if(start == -1)
            return {-1, -1};
        int end = binary_search(nums, target, false);
        return {start, end};
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{5,7,7,8,8,10}, 8, {3, 4}},
            {{5,7,7,8,8,10}, 6, {-1, -1}},
            {{}, 0, {-1, -1}},
            {{1}, 1, {0, 0}},
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.searchRange(test.nums, test.target);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : nums = " << print_array(test.nums) << ", target=" << test.target
        << ", Output = " << print_array(output) << ", Time taken= " << duration.count() << " ms, Result : "
        <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

