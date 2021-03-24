//LeetCode Problem 15 - 3Sum
#include "everything.h"
using namespace std;

struct Test{
    vector<int> input;
    vector<vector<int>> output;
};

class Solution {
    public:        
        string print_array(vector<int> array){
            string ret = "[" ;
            for(int n: array)
                ret += n ;
            return ret + "]" ;
        }
        
        string print_array_of_arrays(vector<vector<int>> arrayOfArrays){
            string ret = "[" ;
            for(auto array : arrayOfArrays)
                ret += print_array(array);
            return ret + "]" ;            
        }

        bool match_array(vector<int> array1, vector<int> array2){
            if (array1.size() != array2.size())
                return false;

            for(int i = 0; i< array1.size() ; i++){
                if(array1[i] != array2[i])
                    return false;
            }
            return true;
        }
        
        bool match_arrays_of_arrays(vector<vector<int>> arrayOfArrays1, vector<vector<int>> arrayOfArrays2){
            if (arrayOfArrays1.size() != arrayOfArrays2.size())
                return false;

            for(int i = 0; i< arrayOfArrays1.size() ; i++){
                if(match_array(arrayOfArrays1[i], arrayOfArrays2[i]))
                    return false;
            }
            return true;
        }
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
                for(int i = 0; i < ret.size(); i++){
                    ret[i][0] = ret[i][0] < i ? ret[i][0] : ret[i][0]+1;
                    ret[i][1] = ret[i][1] < i ? ret[i][1] : ret[i][1]+1;
                    ret[i].push_back(i);
                    sort(ret[i].begin(), ret[i].begin()+ ret[i].size());
                    
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
        cout << "Test #" << ++count << " Input = " << sol.print_array(test.input) << ": Output = " << sol.print_array_of_arrays(ret) << ". Result : " <<  (ret == test.output? green : red) << (sol.match_arrays_of_arrays(ret,test.output)? "Pass" : "Fail") << "!" << def << endl;
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

