//LeetCode Problem 33 - Search in Rotated Sorted Array
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:
 - Find the rotation offset
 - Create a map function using rotation offset
 - Search

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> nums;
    int target;
    int output;
};
class Solution {
    public:
    int find_rotation_offset(vector<int>& nums){
        int left = 0, right = nums.size() - 1;
        while(left < right && nums[left] > nums[right]){
            if(right - left == 1)
                break;
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right])
                left = mid;
            else
                right = mid;
        }
        return right;
    }
    int binary_search(vector<int>& nums, int target, int rot_offset){
        int left = 0, right = rot_offset - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            if(target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        left = rot_offset;
        right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            if(target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int rotation_offset = find_rotation_offset(nums);
        return binary_search(nums, target, rotation_offset);
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{4,5,6,7,0,1,2},0,4},
            {{4,5,6,7,0,1,2},3,-1},
            {{1},0,-1},
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.search(test.nums, test.target);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : nums=" << print_array(test.nums) << ", target="<< test.target << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

