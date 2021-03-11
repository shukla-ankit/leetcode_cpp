//LeetCode Problem 12 - Integer to Roman

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

struct Test{
    int num;
    string output;
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

