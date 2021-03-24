//LeetCode Problem 15 - 3Sum
#include "everything.h"
struct Test{
    vector<int > input;
    vector<vector<int > > output;
};
class Solution {
    public:        
        vector<vector<int>> twoSum(vector<int>& nums, int target) {
            vector<vector<int>> ret;
            map<int, int> mapNumToIndex;            
            for(int i = 0; i< nums.size(); i++){
                if(mapNumToIndex.find(target-nums[i]) == mapNumToIndex.end())
                    mapNumToIndex[nums[i]] = i;			
                else
                    ret.push_back({mapNumToIndex[target - nums[i]], i});
            }
            return ret;
        }
        vector<vector<int>> method(vector<int>& nums){
            vector<vector<int>> retVec;
            
            if(nums.size() < 3) return retVec;

            for(int i = 0; i < nums.size(); i++ ){
                vector<int> subset = nums; 
                subset.erase(nums.begin() + i);
                vector<vector<int>> ret = twoSum(subset, -nums[i]);
                for(int j = 0; j < ret.size(); j++){
                    ret[j][0] = ret[j][0] < i ? ret[j][0] : ret[j][0]+1;
                    ret[j][1] = ret[j][1] < i ? ret[j][1] : ret[j][1]+1;
                    ret[j].push_back(i);
                    sort(ret[j].begin(), ret[j].begin()+ ret[j].size());                    
                    retVec.push_back(ret[i]);
                }
            }
            return retVec;
        }
        /*vector<vector<int>> leetcode_solution(vector<int>& nums){
        }*/
        vector<vector<int>> threeSum(vector<int>& nums){
            return method(nums);
        }
        
};

int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.input = {-1,0,1,2,-1,-4},.output = {{-1,-1,2},{-1,0,1}}},
        {.input = {},.output = {}},
        {.input = {0},.output = {}},
    };
    int count = 0;
    for(auto test: vecTests){        
        auto ret = sol.threeSum(test.input);
        cout << "Test #" << ++count << " Input = " << print_array<int>(test.input) << ": Output = " << print_array_of_arrays<int>(ret) << ". Result : " <<  (match_arrays_of_arrays<int>(ret,test.output)? green : red) << (match_arrays_of_arrays<int>(ret,test.output)? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}
/*
-----------------------------------------------------------------------------------------------------------
method1: <<>>
Similar to TwoSum problem.
1. Pick first element of array
2. Set target = - first element of array
3. Create a mapOfElementToIndex
4. Iterate over elements of array with index not same as Step 1
    5. Check if mapOfElementToIndex has target - current_element 
    7. If yes, then add to return_vector [Step_1_index, mapOfElementToIndex[target - current_element], current_element_index ]
    8. Else, mapOfElementToIndex[current_element] = current_element_index
9. Keep doing this until array ends. 
10. Pick next element of array as Step 1 and repeat steps after it.
11. Return return_vector

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/

