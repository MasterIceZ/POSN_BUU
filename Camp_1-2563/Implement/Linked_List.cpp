#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode (int val, ListNode* next = NULL)
		: val(val), next(next){}
};

// run
int main(){
	ListNode* header = new ListNode(0);
	ListNode* last =  header;
	for(int i=1; i<=5; ++i){
		ListNode* newNode = new ListNode(i);
		last->next = newNode;
		last = newNode;
	}	
	
	ListNode* node = header->next;
	while(node!=NULL){
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	return 0;
}
