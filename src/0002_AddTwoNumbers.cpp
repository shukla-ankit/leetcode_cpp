//LeetCode Problem 2 - 	Add Two Numbers
#include "everything.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ~ListNode(){
        if(next)
            next->~ListNode();        
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr, *temp = nullptr;
    int sum = 0, carry = 0;
    while(l1 != nullptr && l2 != nullptr){
        sum = l1->val + l2->val + carry;
        if(head == nullptr){
            head = new ListNode(sum % 10);
            temp = head;
        }
        else {
            temp->next = new ListNode(sum % 10);
	    temp = temp->next;
        }
        carry = sum / 10;
        l1 = l1 -> next; l2 = l2 -> next;
    }

    while(l1 != nullptr){
        sum = l1->val + carry;
        if(head == nullptr){
            head = new ListNode(sum % 10);
            temp = head;
        }
        else
            temp->next = new ListNode(sum % 10);
        carry = sum / 10;
        l1 = l1 -> next; temp = temp-> next;
    }


    while(l2 != nullptr){
        sum = l2->val + carry;
        if(head == nullptr){
            head = new ListNode(sum % 10);
            temp = head;
        }
        else
            temp->next = new ListNode(sum % 10);
        carry = sum / 10;
        l2 = l2 -> next; temp = temp-> next;
    }


    if(carry)
	    temp->next = new ListNode(carry);

    return head;
}

ListNode* CreateNumList(int num){
    ListNode* temp = nullptr;
    if(num != 0){
        temp = new ListNode(num % 10);
        temp->next = CreateNumList(num/10);
    }
    return temp;
}

void printList(ListNode* l){
    if(l == nullptr)
        return;
    cout << l->val << " -> " ;
    printList(l->next);
}

struct Test{
    vector<vector<int>> Input;
    vector<int> Output;
};

int main(){
    ListNode *num1 = CreateNumList(342), *num2 = CreateNumList(465);
    cout << "Num1 : ";
    printList(num1);
    cout << "\nNum2 : ";
    printList(num2);
    cout << "\nThere sum is : ";
    printList(addTwoNumbers(num1,num2));
    cout << endl;
    num1->~ListNode();
    num2->~ListNode();
    return 0;
}
