//LeetCode Problem 23 - Merge k Sorted Lists

/*
Run two loops - 
1. In outer loop iterate till nums.size() reduces to 1
2. In inner loop ranged from i = 0 to nums.size() - 2  ( which is also < nums.size() -1), 
merge every i-th array array with (i+1) array and then erase the (i+1)-th item from array
3. When incremented a new list will be found, which will be merged with list after it.
4. After first iteration, number of lists will be halved.
5. This will continue till outer loop ends which will be when lists.size() = 1
*/

#include "everything.h"

struct Test{
    vector<vector<int>> nums;
    vector<int> output;
};

class Solution {
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
            
        while(lists.size() > 1){
            for(int i = 0; i < lists.size() - 1; i++){
                lists[i] = mergeTwoLists(lists[i], lists[i + 1]);
                lists.erase(lists.begin()+i+1);
            }
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr, *cur = nullptr;
        while(list1 && list2){
            if(head == nullptr){
                if(list1->val < list2->val){
                    head = list1;
                    list1 = list1-> next;
                }
                else{
                    head = list2;
                    list2 = list2-> next;
                }
                cur = head;
            }
            else{
                if(list1->val < list2->val){
                    cur -> next = list1;
                    list1 = list1-> next;
                }
                else{
                    cur -> next = list2;
                    list2 = list2-> next;
                }
                cur = cur-> next;
            }
        }
        
        while(list1){
            if(head == nullptr){
                head = list1;
            }
            else{
                cur -> next = list1;
            }
        }
        
        while(list2){
            if(head == nullptr){
                head = list2;
            }
            else{
                cur -> next = list2;
            }
        }
        
        return head;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        { .nums={{1,4,5},{1,3,4},{2,6}},.output={1,1,2,3,4,4,5,6}},
        { .nums={},.output={}},
        { .nums={{}},.output={}}
    };
    int count = 0;
    for(auto test: vecTests){
        vector<ListNode*> t;
        for(auto x : test.nums){
            t.push_back(CreateList(x));
        }
        auto output = ConvertToArray(sol.mergeKLists(t));
        bool bIsPass = match_array(output,test.output);
        cout << "Test #" << ++count << " : Input = " << print_array_of_arrays(test.nums) << ", Output = " << print_array(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
	return 0;
}
/*
-----------------------------------------------------------------------------------------------------------
method1: <<>>
-----------------------------------------------------------------------------------------------------------
Leetcode Method:

-----------------------------------------------------------------------------------------------------------
*/

