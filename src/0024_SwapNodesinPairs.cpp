//LeetCode Problem 24 - Swap Nodes in Pairs
/*
1. Copying nodes from given list to other list
2. Start with ptr = head
3. while( ptr != NULL):
    firstNode = ptr
    secondNode = ptr->next ? ptr->next : NULL;

    if(secondNode){
        firstNode->next = secondNode -> next
        seconfNode->next = firstNode
    }

    Add secondNode first to new list and then the firstNode
    If secondnode doesn't exist, add the firstNode directly

    Increment ptr only once as ptr is already pointing to firstNode which has become secondNode
*/


#include "everything.h"

struct Test{
    vector<int> input;
    vector<int> output;
};
class Solution {
    public:
    void print(ListNode* head){
        std::cout << "List :";
        while(head){
            std::cout << head->val << " -> ";
            head = head->next;
        }
        std:cout << "0" << endl;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode* newhead = nullptr, *ptr = head, *r_ptr = nullptr;
        
        while(ptr){
            ListNode* firstNode = ptr;
            ListNode* secondNode = nullptr;
            if(ptr -> next){
                secondNode = ptr->next;
                firstNode->next = secondNode -> next;
                secondNode -> next = firstNode;
            }
                
            if(newhead == nullptr){
                if(secondNode)
                    newhead = secondNode;                    
                else
                    newhead = firstNode;
            }
            else{
                if(secondNode){
                    r_ptr->next = secondNode;
                }
                else
                    r_ptr->next = firstNode;
            }
            r_ptr = firstNode;
            if(secondNode)
                ptr = ptr->next;
            else
                break;
        }
        return newhead;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.input={1,2,3,4} , .output={2,1,4,3}},
        {.input={} , .output={}},
        {.input={1} , .output={1}},
        {.input={1,2,3,4,5,6,7,8,9} , .output={2,1,4,3,6,5,8,7,9}},
        {.input={1,2,3,4,5,6,7,8} , .output={2,1,4,3,6,5,8,7}}
    };
    int count = 0;
    for(auto test: vecTests){
        auto output = ConvertToArray(sol.swapPairs(CreateList(test.input)));
        bool bIsPass = match_array(output, test.output);
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", Output = " << print_array(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

