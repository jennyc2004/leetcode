//============================================================================
// Name        : linkedlist_mergeTwoLists.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr){}
	ListNode(int x): val(x), next(nullptr){}
	ListNode(int x, ListNode *next): val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l1 == nullptr) return l2;
    	if(l2 == nullptr) return l1;
    	ListNode *result;
    	if(l1->val <= l2->val){
    		result = new ListNode(l1->val);
    		result->next = mergeTwoLists(l1->next, l2);
    	}else{
    		result = new ListNode(l2->val);
    		result->next = mergeTwoLists(l1, l2->next);
    	}
        return result;
    }
};

int main()
{
	Solution s;
	ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
	ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
	ListNode *l = s.mergeTwoLists(l1, l2);
	while(l){
		cout<<l->val<<",";
		l = l->next;
	}
	return 0;
}
