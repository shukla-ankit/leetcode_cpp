//LeetCode Problem 43 - Multiply Strings
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:
 1. Parse the strings like ABCD x PQRS while convert chars to digits with two loops.
    Outer loop has parses right to left on second string, multiplying it with individual digits on first string
    Inner loop is on first string, parsing right to left.

2. Add and update carry in each muyltiplication.

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    string num1;
    string num2;
    string output;
};
class Solution {
    public:

    void remove_extra_zeroes(string &s){
        int start = 0, i=0;
        while(i < s.length() && s[i++] == '0')
            start++;
        if(s.length() == start)
            start--;
        s = s.substr(start, s.length() - start);
    }

    string add(string num1, string num2){
        string ret;
        int num1_idx = num1.size()-1, num2_idx = num2.size()-1, carry = 0;
        while(num1_idx >=0 && num2_idx >= 0){
            string temp;
            int t = (num1[num1_idx] - '0') + (num2[num2_idx] - '0') + carry;
            carry = t / 10;
            temp.push_back('0' + t % 10);
            ret = temp + ret;
            num1_idx--;
            num2_idx--;
        }
        while(num1_idx >=0){
            string temp;
            int t = (num1[num1_idx] - '0') + carry;
            carry = t / 10;
            temp.push_back('0' + t % 10);
            ret = temp + ret;
            num1_idx--;
        }
        while(num2_idx >= 0){
            string temp;
            int t = (num2[num2_idx] - '0') + carry;
            carry = t / 10;
            temp.push_back('0' + t % 10);
            ret = temp + ret;
            num2_idx--;
        }
        if(carry) {
            string temp;
            temp.push_back('0' + carry);
            ret = temp + ret;
        }
        remove_extra_zeroes(ret);
        return ret;
    }

    string multiply(string num1, string num2){
        string ret = "0";
        if(num1.length() < num2.length())
            return multiply(num2, num1);
        remove_extra_zeroes(num1);
        remove_extra_zeroes(num2);
        if(num1.size() < num2.size()){
            string t = num1;
            num1 = num2;
            num2 = t;
        }

        for(int num1_idx = num1.size()-1; num1_idx >= 0; num1_idx--){
            int carry = 0;
            string one_digit_product;
            for(int num2_idx = num2.size()-1; num2_idx >= 0; num2_idx--) {
                int t = (num1[num1_idx] - '0') * (num2[num2_idx] - '0') + carry;
                carry = t / 10;
                string temp;
                temp.push_back('0' + t % 10);
                one_digit_product = temp + one_digit_product;
            }
            string temp;
            temp.push_back('0' + carry);
            one_digit_product = temp + one_digit_product;
            ret = add(ret, one_digit_product + string(num1.size() - 1 - num1_idx, '0'));
        }
        return ret;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {"999", "999", "998001"},
            {"027", "000000", "0"},
            {"2", "3", "6"},
            {"123", "12", "1476"},
            {"123", "456", "56088"},
            {"027", "08", "216"},
            {"111111111", "111111111", "12345678987654321"}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        //auto output = sol.add(test.num1, test.num2);
        auto output = sol.multiply(test.num1, test.num2);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.output;
        time += duration.count();
        cout << "Test #" << ++count << " : num1=\"" << test.num1 << "\": num2=\"" << test.num2 << "\", Output = \""
        << output << "\", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red)
        << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

