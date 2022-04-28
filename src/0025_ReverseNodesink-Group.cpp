//LeetCode Problem 25 - Reverse Nodes in k-Group
#include "everything.h"

/*
1. Think of it as copying these nodes to a different list in groups of k in reversed order
2. Iterate over the list and Read a group of k nodes and store them in an array
3. If list ends before getting k elements, assign the start pointer of list from original
        list to tail of new list
   Else, iterate over the array from reverse (k-1 to 1) and in the next pointer of 
    current i-th node assign (i-1)th node
4. FOr 0-th element, in next field assign nullptr
5. Assign (k-1)th node in array to next at the tail of new list
6. Update parsed ptr with the temp ptr from parsing k nodes from list. It may be nullptr or 
    (k+1)th node in original list. 
*/

struct Test{
    vector<int> input;
    int k;
    vector<int> output;
};
class Solution {
    public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newhead = nullptr, *newptr = nullptr, *ptr = head;
        
        while(ptr){
            ListNode* temp = ptr;
            vector<ListNode*> m;
            for(int i=0; i < k && temp; i++){
                m.push_back(temp);
                temp = temp-> next;
            }
            if(m.size() != k){
                if(newhead == nullptr)
                    newhead = ptr;
                else
                    newptr -> next = ptr;
                break;     
            }
            else{          
                for(int i = k-1; i >0; i--){
                    m[i]->next = m[i-1];
                }
                m[0]->next = nullptr;            
                if(newhead == nullptr)
                    newhead = m[k-1];
                else
                    newptr->next = m[k-1];
                newptr = m[0];
            }      
            ptr = temp;
        }
        return newhead;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
        {.input={1,2,3,4,5}, .k=2, .output={2,1,4,3,5}},
        {.input={1,2,3,4,5}, .k=3, .output={3,2,1,4,5}},
    };

    int count = 0;
    for(auto test: vecTests){
        auto output = ConvertToArray(sol.reverseKGroup(CreateList(test.input), test.k));
        bool bIsPass = match_array(output, test.output);
        cout << "Test #" << ++count << " : Input = " << print_array(test.input) << ", k="<< test.k << ", Output = " << print_array(output) << ". Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
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

