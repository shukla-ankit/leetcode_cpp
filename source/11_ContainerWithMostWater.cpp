//LeetCode Problem 11 - Container With Most Water

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
#include "colormod.h"
using namespace std;

Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);

class Solution {
    public:
        int min(int a, int b){
            return a < b? a: b;
        }

        int area(vector<int>& height, int left, int right){
            return (right - left) * min(height[left], height[right]);
        }

        int maxArea(vector<int>& height) {
            int left = 0, right = height.size()-1, max_area = area(height, left, right);
            while(left < right){
                if(height[left] < height[right])
                    left++;                
                else
                    right--;
                int a = area(height, left, right);
                if( max_area < a)
                    max_area = a;                
            }
            return max_area;
        }
};

struct Test{
    vector<int> height;
    int output;
};

int main() {
    Solution sol;
    vector<Test> vecTests = {
        {{1,8,6,2,5,4,8,3,7}, 49},
        {{1,1}, 1},
        {{4,3,2,1,4}, 16},
        {{1,2,1}, 2},
        {{1,3,2,5,25,24,5},24}
    };
    int count = 0;
    for(auto test: vecTests){        
        int ret = sol.maxArea(test.height);
        cout << "Test #" << ++count << " : Output = " << ret << ". Result : " <<  (ret == test.output? green : red) << (ret == test.output ? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}
