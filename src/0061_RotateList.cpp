//LeetCode Problem 61 - Rotate List
/*
-----------------------------------------------------------------------------------------------------------
Approach 1:

-----------------------------------------------------------------------------------------------------------
*/
#include "everything.h"

struct Test{
    vector<int> head;
    int k;
    vector<int> output;
};
class Solution {
    public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ptr = head;
        int counter = 0, length = -1;
        while(ptr != nullptr) {
            ++counter;
            ptr = ptr->next;
        }
        length = counter;
        k = k % length;
        counter = 0;
        ptr = head;
        ListNode *temp = head;
        while(temp->next != nullptr){
            if(counter++ >= k)
                ptr = ptr->next;
            temp = temp->next;
        }
        temp->next = head;
        head = ptr -> next;
        ptr->next = nullptr;
        return head;
    }
};
int main() {
    Solution sol;
    vector<Test> vecTests = {
            {{1,2,3,4,5}, 2, {4,5,1,2,3}},
            {{0,1,2}, 4, {2,0,1}}
    };
    int count = 0, time = 0;
    for(auto test: vecTests){
        auto start = high_resolution_clock::now();
        auto output = sol.rotateRight(CreateList(test.head), test.k);
        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
        bool bIsPass = match_array(ConvertToArray(output),test.output);
        time += duration.count();
        cout << "Test #" << ++count << " : array = " << print_array(test.head) << ", k=" <<
        test.k << ", Output = " << print_array(ConvertToArray(output)) << ", Time taken= " << duration.count()/1000.0 << " ms, Result : " <<  (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << "!" << def << endl;
    }
    cout << "Total time taken = " << (time/1000.0) << " ms." << endl;
	return 0;
}

