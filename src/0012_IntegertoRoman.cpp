//LeetCode Problem 12 - Integer to Roman
/*
1. Create a map from int to roman numbers
2. Parse given number from units place to above by current_num = num % 10 and num /=10 to iterate.
3. Also maintain a counter to identify which unit's place in the number (i.e. div)
4. Keep looking up and adding in begining of return string. Repeat when repeatition required.
*/


#include "everything.h"
using namespace std;

struct Test{
    int num;
    string output;
};

class Solution {
    public:
        map<int, string> mapIntToRoman = {
            {1, "I"},{5, "V"},{10, "X"},{50, "L"},{100, "C"},{500, "D"},{1000, "M"}
        };

        string repeat(string s, int times){
            string ret;
            while(times--)
                ret += s;
            return ret;
        }
        
        string intToRoman(int num) {
            string ret;
            int div = 10;            
            while(num % 10|| num / 10){
                if(num % 10 == 0){
                    num /= 10;
                    div *= 10;
                    continue;
                }
                else if(num % 10 < 4)
                    ret = repeat(mapIntToRoman[div/10], num % 10) + ret;
                else if(num % 10 == 4)
                    ret = mapIntToRoman[div/10] + mapIntToRoman[div*5/10] + ret;
                else if(num % 10 == 5)
                    ret = mapIntToRoman[div*5/10] + ret;
                else if(num % 10 < 9)
                    ret = mapIntToRoman[div*5/10] + repeat(mapIntToRoman[div/10], num % 10 - 5) + ret;
                else if(num % 10 == 9)
                    ret = mapIntToRoman[div/10] + mapIntToRoman[div] + ret;
                num /= 10;
                div *= 10;
            }
            return ret;
        }
};

int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.num=100, .output = "C"},
        {.num=110, .output = "CX"},
        {.num=3, .output = "III"},
        {.num=4, .output = "IV"},
        {.num=9, .output = "IX"},
        {.num=58, .output = "LVIII"},
        {.num=1994, .output = "MCMXCIV"},
    };
    int count = 0;
    for(auto test: vecTests){        
        string ret = sol.intToRoman(test.num);
        cout << "Test #" << ++count << " : Input = " << test.num << ", Output = " << ret << ". Result : " <<  (ret == test.output? green : red) << (ret == test.output? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}

