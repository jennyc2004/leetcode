//============================================================================
// Name        : linkedlist_addTwoNumbers.cpp
// Author      : Jenny Cheng
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================
using namespace std;
#include <iostream>
#include <vector>

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL && l2 == NULL) return NULL;
    	if(l1 == NULL) return l2;
    	if(l2 == NULL) return l1;
        int cur = l1->val + l2->val;
        ListNode *result = new ListNode(cur % 10);
        result->next = addTwoNumbers(l1->next, l2->next);
        if(cur >= 10) result->next = addTwoNumbers(result->next, new ListNode(1));
        return result;
    }
};

int main()
{
	Solution s;
	//342 + 465 = 807
	ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
	ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

	ListNode* l = s.addTwoNumbers(l1, l2);
	for(ListNode* temp = l; temp != NULL; temp = temp->next){
		cout<<temp->val;
	}
	return 0;
}
