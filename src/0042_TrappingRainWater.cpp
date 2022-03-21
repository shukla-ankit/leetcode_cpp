//LeetCode Problem 42 - Trapping Rain Water
/*
-----------------------------------------------------------------------------------------------------------
Approach stack:

Approach DP:
    - Create two arrays left_max and right_max of size height
    - parse over height 0 to n- 1 and set left_max
    - parse over height n- 1 to 0 and set right_max
    - parse over height 0 to n-1 and compute sum = sum + min(left_max[i],right_max[i]) - height[i]

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
        //return approach_stack(height);
        //return approach_dp(height);
        return approach_left_right(height);
    }
    int approach_stack(vector<int>& height) {
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

    int approach_dp(vector<int>& height) {
        if(height.empty())
            return 0;

        int sum = 0;
        vector<int> left_max(height.size(), -1), right_max(height.size(), -1);

        left_max[0] = height[0];
        for(int i=1; i < height.size(); i++)
            left_max[i] = max(left_max[i-1], height[i]);

        right_max[height.size()-1] = height[height.size()-1];
        for(int i=height.size()-2; i>=0; i--)
            right_max[i] = max(right_max[i+1], height[i]);

        for(int i=1; i < height.size(); i++)
            sum += min(left_max[i], right_max[i]) - height[i];

        return sum;
    }

    int approach_left_right(vector<int>& height) {
        if(height.empty())
            return 0;

        int sum = 0, left = 0, right = height.size() -1, left_max = height[0], right_max = height[height.size()-1];
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] > left_max)
                    left_max = height[left];
                else
                    sum += left_max - height[left];
                left++;
            }
            else{
                if(height[right] > right_max)
                    right_max = height[right];
                else
                    sum += right_max - height[right];
                right--;
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

