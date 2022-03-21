//LeetCode Problem 42 - Trapping Rain Water
/*
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> input;
    int output;
};
struct Data{
        int index;
        int height;
};
class Solution {
    public:
        int trap(vector<int>& height) {
        int sum = 0, left_max = -1, right_max = -1;
        vector<Data> rightMax;        
        for(int i=height.size()-1; i>=0; i--){
            if(right_max < height[i]){
                rightMax.push_back({i, height[i]});
                right_max = height[i];
            }
        }
        for(int i=0; i<height.size(); i++){
            if(left_max < height[i])
                left_max = height[i];
            if(i == rightMax[rightMax.size()-1].index)
                rightMax.pop_back();            
            else{
                int l = min(left_max, rightMax[rightMax.size()-1].height) - height[i];
                sum += l > 0? l : 0;
            }
        }   
        return sum;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{0,1,0,2,1,0,1,3,2,1,2,1}, 6},
            {{4,2,0,3,2,5}, 9},
            {{4,2,3},1}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.trap(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

