//LeetCode Problem 1 - Two Sum

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> mapNumToIndex;
		for(int i = 0; i< nums.size(); i++){
			if(mapNumToIndex.find(target-nums[i]) == mapNumToIndex.end())
				mapNumToIndex[nums[i]] = i;			
			else
				return {mapNumToIndex[target - nums[i]], i};
		}
		return {-1, -1};
    }
};

int main() {
	Solution s;
	vector<vector<int>> vecTestcases = {
		{2,7,11,15},
		{3,2,4},
		{3,3}
	};
	vector<int> vecTarget = {9, 6, 6};
	for(int i = 0; i < vecTestcases.size(); i++){
		vector<int> op = s.twoSum(vecTestcases[i],vecTarget[i]);	
		cout << "[" << op[0] << "," << op[1] << "]"<< endl;
	}
	return 0;
}
