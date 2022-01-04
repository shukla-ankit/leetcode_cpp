/*
LeetCode Problem 31 - Next Permutation

Very good problem!!
Explanation here: https://leetcode.com/problems/next-permutation/solution/

*/

#include "everything.h"
struct Test{
    vector<int> input;
    vector<int> output;
};
class Solution {
    public:
        void nextPermutation2(vector<int>& nums) {
            //Find the ascending peak closest to Lowest Significant Bits
            int i = nums.size()-1;
            for(; i >=1; i--)
                if(nums[i] > nums[i-1])
                    break;

            //If you don't find and reach to begining, return sorted sequence
            if(i == 0){
                sort(nums.begin(), nums.end());
                return;
            }

            //Else, 
            //the (i - 1) number which is foot of ascending peak needs to be swapped
            // with a number on right side, which is smallest among the other numbers
            // on right side, but bigger than (i -1)th number
            int just_bigger_on_right = i;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] > nums[i-1] && nums[j] < nums[just_bigger_on_right])
                    just_bigger_on_right = j;
            }
            swap(nums[just_bigger_on_right], nums[i-1]);

            //Once swapping is done, sort the numbers on right side to (i-1)
            sort(nums.begin()+i, nums.end());
        }


        void nextPermutation1(vector<int>& nums) {        
            std::next_permutation(nums.begin(), nums.end()); // Almost like cheating!            
        }
        void method(vector<int>& nums){
            nextPermutation2(nums);
        }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
                                {.input={1,2,3},.output={1,3,2}},
                                {.input={3,2,1},.output={1,2,3}},
                                {.input={1,1,5},.output={1,5,1}},
                                {.input={1,5,3,4,2},.output={1,5,4,2,3}},

                            };
    int count = 0;
    for(auto test: vecTests){
        auto output = test.input;
        sol.method(output);
        bool bIsPass = match_array<int>(test.output, output);
        cout << "Test #" << ++count << " : Input = " << print_array<int>(test.input) << ", Output = " << print_array<int>(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

