#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    unordered_set<int> setLookUp;
    for(int i = 0 ; i < nums.size(); i++) {
        if (setLookUp.find(target - nums[i]) != setLookUp.end()) {
            ret.push_back(find(nums.begin(), nums.end(), target - nums[i]) - nums.begin());
            ret.push_back(i);
        }
        if (setLookUp.find(nums[i]) == setLookUp.end())
            setLookUp.insert(nums[i]);
    }
    return ret;
}


int main(){
    vector<int> myVec = {5, 8, 15, 2, 7, 11, 15};
    int target = 9;
    cout << "Indices of two numbers whose sum is " << target << " are ";
    vector<int> ret = twoSum(myVec, target);
    for(auto x: ret){
        cout << x << " ";
    }
    return 0;
}