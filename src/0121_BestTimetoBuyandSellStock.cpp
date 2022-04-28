//LeetCode Problem 121 - Best Time to Buy and Sell Stock
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> prices;
    int output;
};
class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int maxprofit = 0, lowest = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(i != 0)
                maxprofit = maxprofit > prices[i] - lowest ? maxprofit : prices[i] - lowest;
            lowest = lowest < prices[i] ?  lowest : prices[i];
        }
        return maxprofit;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.prices={7,1,5,3,6,4}, .output=5},
            {.prices={7,6,4,3,1}, .output=0}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.maxProfit(test.prices);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.prices) << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

