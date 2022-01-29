/*
LeetCode Problem 31 - Next Permutation
    Approach:
    - Think of array values as columns with heights equal to their values
    - Parse array from right side till you find a peak i.e. left and right values are smaller than current
    - If peak is at i = 0, this is highest value permutation. Next permutation will be sequence in ascending form.
        Sort the array in ascending order and return it.
    - Else, take left foot of peak and swap it with next bigger number on right side. And sort the rest of the sequence
    from foot+1 to end in ascending order and return the sequence.

 Explanation here: https://leetcode.com/problems/next-permutation/solution/
*/

#include "everything.h"
struct Test{
    vector<int> input;
    vector<int> output;
};
class Solution {
    public:
    void swap(int &a, int &b){
        a = a+b;
        b = a-b;
        a = a-b;
    }
    void my_NextPermutation(vector<int>& nums) {
        int foot = nums.size() -2;
        for(; foot >=0 ; foot--){
            if(nums[foot] < nums[foot+1])
                break;
        }
        if(foot == -1)
            return sort(nums.begin(), nums.end());

        int diff = INT_MAX, slightly_more_idx = -1;
        for(int i = nums.size()-1; i > foot ; i--){
            int d = nums[i] - nums[foot];
            if( d > 0 && diff > d){
                diff = d;
                slightly_more_idx = i;
            }
        }

        cout << foot << " " << slightly_more_idx ;
        swap(nums[foot], nums[slightly_more_idx]);
        sort(nums.begin() + foot + 1, nums.end());
    }
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
        sol.my_NextPermutation(output);
        bool bIsPass = match_array<int>(test.output, output);
        cout << "Test #" << ++count << " : Input = " << print_array<int>(test.input) << ", Output = " << print_array<int>(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}
