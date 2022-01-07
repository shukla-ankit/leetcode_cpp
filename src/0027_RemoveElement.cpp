//LeetCode Problem 27 - Remove Element
#include "everything.h"

/*
approach 1: use erase to remove elements with value val from vector

appproach 2: use a second index to write unique elements on same array. First index traverses 
array to check which elements are equal to "val" and second index writes them on same array and 
incrementing, only when an equal integer is found.
*/

struct Test{
    vector<int> input;
    int val;
    int k;
    vector<int> output;
};
class Solution {
    public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val)
                nums[j++] = nums[i];
        }
        return j;
    }

    int removeElement2(vector<int>& nums, int val) {
        for(int i = 0; i < nums.size(); ){
            if(nums[i] == val)
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
        {{3,2,2,3},3,2,{2,2,2,3}},
        {{0,1,2,2,3,0,4,2},2,5,{0,1,3,0,4,0,4,2}},
        {{},0,{}}
    };
    int count = 0;
    for(auto test: vecTests){        
        vector<int> o(test.input);
        auto k = sol.removeElement(o, test.val);
        bool bIsPass = match_array(o,test.output) && k == test.k;
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", val =" << test.val << ", Output = " << print_array(o) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

