//LeetCode Problem 21 - Merge Two Sorted Lists
#include "everything.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Test{
    vector<int> nums1;
    vector<int> nums2;
    vector<int> output;
};

class Solution {
    public:
        ListNode* CreateList(vector<int> nums){
        ListNode *ret = nullptr, *ptr = nullptr;
        for(auto n : nums){
            if(ret == nullptr){
                ret = new ListNode(n);
                ptr = ret;
            }
            else{
                ptr -> next = new ListNode(n);
                ptr = ptr->next;
            }
        }
        return ret;
    }
    
    vector<int> ConvertToArray(ListNode* head){
        vector<int> ret;
        while(head){
            ret.push_back(head->val);
            head = head -> next;
        }
        return ret;
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
                cur = head;
                list1 = list1-> next;
            }
            else{
                cur -> next = list1;
                list1 = list1-> next;
                cur = cur-> next;
            }
        }
        
        while(list2){
            if(head == nullptr){
                head = list2;
                cur = head;
                list2 = list2-> next;
            }
            else{
                cur -> next = list2;
                cur = cur-> next;
                list2 = list2-> next;
            }
        }
        
        return head;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        { .nums1={1,2,4},.nums2={1,3,4},.output={1,1,2,3,4,4}},
        { .nums1={},.nums2={},.output={}},
        { .nums1={},.nums2={0},.output={0}}
    };
    int count = 0;
    for(auto test: vecTests){        
        auto output = sol.ConvertToArray(sol.mergeTwoLists(sol.CreateList(test.nums1), sol.CreateList(test.nums2)));
        bool bIsPass = match_array(output,test.output);
        cout << "Test #" << ++count << " : Input = " << print_array(test.nums1) + print_array(test.nums2) << ", Output = " << print_array(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

