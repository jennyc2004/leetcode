//============================================================================
// Name        : linkedlist_copyRandomList.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;
        Node* newHead = new Node(0);
        Node* copied = newHead;
        Node* cur = head;
        //deep copy of original node, map old to new node
        while(cur){
        	Node* temp = new Node(cur->val);
        	copied->next = temp;
        	copied = copied->next;
        	nodeMap[cur] = copied;
        	cur = cur->next;
        }
        Node* trackCopy = newHead->next;
        Node* trackOrig = head;
        while(trackCopy){
        	trackCopy->random = nodeMap[trackOrig->random];
        	trackCopy = trackCopy->next;
        	trackOrig = trackOrig->next;
        }
        return newHead->next;

    }
};

int main()
{
	Solution s;
	Node* n0 = new Node(7);
	Node* n1 = new Node(13);
	Node* n2 = new Node(11);
	Node* n3 = new Node(10);
	Node* n4 = new Node(1);
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	n0->random = NULL;
	n1->random = n0;
	n2->random = n4;
	n3->random = n2;
	n4->random = n0;
	Node* head = s.copyRandomList(n0);
	while(head != NULL){
		cout<<head->val<<",";
		head = head->next;
	}
	cout<<endl;
	return 0;
}
