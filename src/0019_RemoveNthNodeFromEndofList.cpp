//LeetCode Problem 19 - Remove Nth Node From End of List
#include "everything.h"

/*
 * Approach 1:
 *  Parse the list and count nodes
 *  subtract n from the count and parse nodes again for (count -n ) nodes. Keeping a prev pointer
 *  Alter the next in previous. Take care if it is start node.
 *
 * Approach 2:
 *  Parse the list and count nodes
 *  If count > n :
 *      if temp = nullptr, set temp = head, else temp = temp->next
 *  if count == n, move head to next and delete head
 *  if count > n, delete the node after temp and set temp-> next to temp -> next -> next;
*/

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

struct Test{
    vector<int> nums;
    int n;
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
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode* ptr = head, *prev = nullptr;
        int countNodes = 0;
        while(ptr){
            ptr = ptr -> next;
            countNodes++;
        }

        ptr = head;

        countNodes -= n;

        while(countNodes--){
            prev = ptr;
            ptr = ptr-> next;
        }

        if(ptr == head){
            head = head -> next;
            delete ptr;
        }
        else{
            prev -> next = ptr -> next;
            delete ptr;
        }
        return head;
    }

    ListNode* removeNthFromEnd2(ListNode* head, int n) {
		ListNode *ptr = head, *temp = nullptr;
        int count = 0;
        while(ptr) {
            if(++count > n){
                if(temp == nullptr)
                    temp = head;
                else
                    temp = temp->next;
            }
            ptr = ptr->next;
        }
        if(count == n){
            ptr = head;
            head = head->next;
            delete ptr;
        }
        else if(count > n){
            if(temp->next) {
                ListNode *del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
        }
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNthFromEnd2(head, n);
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {.nums={1,2,3,4,5}, .n=2, .output = {1,2,3,5}},
        {.nums={1}, .n=1, .output = {}},
        {.nums={1, 2}, .n=1, .output = {1}}
    };
    int count = 0;
    for(auto test: vecTests){        
        auto output = sol.ConvertToArray(sol.removeNthFromEnd(sol.CreateList(test.nums), test.n));
        bool bIsPass = match_array(output, test.output);
        cout << "Test #" << ++count << " : nums = " << print_array(test.nums) << ", n = " << test.n <<
        ", Output = " << print_array (output) << ". Result : " <<  (bIsPass? green : red) <<
        (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

