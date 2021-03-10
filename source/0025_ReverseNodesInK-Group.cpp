//LeetCode Problem 25 - Reverse Nodes in k-Group

#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* CreateLinkedList(int k) {
		ListNode *head = nullptr, *temp = nullptr;
		while(k){
			if(head == nullptr){
				head = new ListNode(k%10);
				temp = head;				
			}
			else{
				temp -> next = new ListNode(k%10);
				temp = temp -> next;								
			}
			k /= 10;
		}
		return head;
    }
	
	void printLinkedList(ListNode* l){
		cout << "Linked list : " ;
		while(l){
		 cout << l->val << " -> " ;
		 l = l -> next;
		}
		cout << endl;		
	}
	ListNode* reverseLinkedList(ListNode* head) {
		ListNode* temp = head, *fwd = nullptr;
		
		fwd = head -> next;		
		head -> next = nullptr;
		
		while(fwd){
			temp = fwd;
			fwd = fwd -> next;
			temp -> next = head;
			head = temp;
		}
		return head;
    }
	
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* temp = head, *fwd = nullptr, *back = nullptr;
		
		fwd = head -> next;		
		head -> next = nullptr;
		int i = k;
		while(fwd ){
			if(i ==k){
				back = head;				
			}
			else if(i ==0){
				i = k;
			}
			else{
				temp = fwd;
				fwd = fwd -> next;
				temp -> next = head;
				head = temp;
			}
			i--;
		}
		return head;
    }
};

int main(){
	Solution s;
	ListNode* start = s.CreateLinkedList(123456789);
	s.printLinkedList(start);
	
	int n_rev = 3;
	start = s.reverseKGroup(start, n_rev);
	s.printLinkedList(start);
	
	return 0;
}