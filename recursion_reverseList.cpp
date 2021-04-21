//============================================================================
// Name        : recursion_reverseList.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL || head->next == NULL) return head;
    	int val = head->val;
    	ListNode* final = reverseList(head->next);
    	head->next->next = head;
    	head->next = NULL;
    	return final;
    }
};

int main()
{
	Solution s;
	ListNode* node = new ListNode(1, new ListNode(2, new ListNode(3)));
	ListNode* rev = s.reverseList(node);
	while(rev){
		cout<<rev->val<<",";
		rev = rev->next;
	}
	cout<<endl;
	return 0;
}
