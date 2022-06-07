//LeetCode Problem 104 - Maximum Depth of Binary Tree
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:
1. if root is null return 0
   else return 1 + max( max_depth(left_subtree),  max_depth(right_subtree))
-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    TreeNode * root;
    int depth;
};
class Solution {
    public:
    //Recursion
    int maxDepth(TreeNode* root) {
        if(root)
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        return 0;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {CreateTreeBFS({3,9,20,0,0,15,7}), 3},
            {CreateTreeBFS({1,0,2}), 2}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.maxDepth(test.root);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = output == test.depth;
        time += duration.count();
        cout << "Test #" << ++count << " : Input = " << test.depth << ", Output = " << output << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

