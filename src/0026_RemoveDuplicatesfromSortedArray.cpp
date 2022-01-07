//LeetCode Problem 26 - Remove Duplicates from Sorted Array
/*
approach 1: use erase to remove duplicate elements from vector

appproach 2: use a second index to write unique elements on same array. First index traverses 
array to check which elements are unique and second index writes them on same array and 
incrementing, only when a unique integer is found.
*/


#include "everything.h"

struct Test{
    vector<int> input;
    int k;
    vector<int> output;
};
class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        
        int k = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1])
                nums[k++] = nums[i];
        }
        return k;
    }

    int removeDuplicates2(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ){
            if(nums[i] == nums[i-1])
                nums.erase(nums.begin() + i);
            else
                i++;
        }
        return nums.size();
    }

};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        {{1,1,2},2,{1,2,2}},
        {{0,0,1,1,1,2,2,3,3,4},5,{0,1,2,3,4,2,2,3,3,4}},
        {{},0,{}}
    };
    int count = 0;
    for(auto test: vecTests){        
        vector<int> o(test.input);
        auto k = sol.removeDuplicates(o);
        bool bIsPass = match_array(o,test.output) && k == test.k;
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", k=" << k << ", Output = " << print_array(o) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

