//LeetCode Problem 66 - Plus One
/*
-----------------------------------------------------------------------------------------------------------
Approach 1: Time Complexity O(n)
 1. Parse the entire array and keep adding and Updating carry.

Approach 2: Time Complexity O(n) - But better than Approach 1
 1. Parse the input array backwards
 2. If you find 9, update it to 0 and decrement the index.
 3. If you find anything else than 9, increment that number and return the array. Therefore, no parse the entire array.
-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> input;
    vector<int> output;
};
class Solution {
public:
    vector<int> plusOne1(vector<int>& digits) {
        vector<int> ret;
        ret.resize(digits.size());
        int carry = 0;
        ret[ret.size()-1] = (digits[ret.size()-1] + 1) % 10;
        carry =  (digits[ret.size()-1] + 1) / 10;
        for(int i = digits.size()-2; i>=0; i--){
            ret[i] = (digits[i] + carry) % 10;
            carry =  (digits[i] + carry) / 10;
        }
        if(carry){
            auto it = ret.begin();
            ret.insert(it, carry);
        }
        return ret;
    }

    vector<int> plusOne2(vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size()-1; i>=0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
                carry = 1;
            }
            else{
                digits[i]++;
                return digits;
            }
        }
        auto it = digits.begin();
        digits.insert(it, 1);
        return digits;
    }
    vector<int> plusOne(vector<int>& digits) {
        return plusOne2(digits);
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{1,2,3},{1,2,4}},
            {{4,3,2,1},{4,3,2,2}},
            {{9},{1, 0}},
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.plusOne(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " << print_array(output) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

