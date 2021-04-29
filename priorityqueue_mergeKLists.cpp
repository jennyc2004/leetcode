//============================================================================
// Name        : priorityqueue_mergeKLists.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
private:
	  struct compare{
		  bool operator()(ListNode* node1, ListNode* node2){
			  return node1->val > node2->val;
		  }
	  };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    	priority_queue<ListNode*, vector<ListNode*>, compare> listQ;
    	for(auto node: lists) {
    		if(node) listQ.push(node);
    	}
    	if(listQ.empty()) return NULL;
    	ListNode* result = listQ.top();
    	listQ.pop();
    	if(result->next) listQ.push(result->next);
    	ListNode * temp = result;
    	while(!listQ.empty()){
    		temp->next = listQ.top();
    		listQ.pop();
    		temp = temp->next;
    		if(temp->next) listQ.push(temp->next);
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	ListNode * node1 = new ListNode(1, new ListNode(2, new ListNode(5)));
	ListNode * node2 = new ListNode(1, new ListNode(3, new ListNode(4)));
	ListNode * node3 = new ListNode(2, new ListNode(6));
	vector<ListNode*> lists {node1, node2, node3};
	ListNode* node = s.mergeKLists(lists);
	while(node){
		cout<<node->val<<",";
		node = node->next;
	}
	return 0;
}
