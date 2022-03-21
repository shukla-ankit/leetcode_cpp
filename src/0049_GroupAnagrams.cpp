//LeetCode Problem 49 - Group Anagrams
/*
-----------------------------------------------------------------------------------------------------------
My Method:

-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<string> input;
    vector<vector<string>> output;
};
class Solution {
    public:
    string getCategory(string str){
        sort (str.begin(), str.end());
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mapStringToCategory;
        vector<vector<string>> retAnagramGroups;

        for (auto s: strs) {
            string str = getCategory(s);
            if (mapStringToCategory.find(str) == mapStringToCategory.end())
                mapStringToCategory[str] = {};
            mapStringToCategory[str].push_back(s);
        }
        for (auto a: mapStringToCategory) {
            auto t = mapStringToCategory[a.first];
            sort(t.begin(), t.end());
            retAnagramGroups.push_back(t);
        }
        return retAnagramGroups;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{"eat","tea","tan","ate","nat","bat"}, {{"bat"},{"nat","tan"},{"ate","eat","tea"}}},
            {{""}, {{""}}}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.groupAnagrams(test.input);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = std::equal(output.begin(), output.end(), test.output.begin());
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " <<
        print_array_of_arrays(output) << ", Expected = " << print_array_of_arrays(test.output)
        << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) <<
        (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

