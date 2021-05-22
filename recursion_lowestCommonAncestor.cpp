//============================================================================
// Name        : recursion_lowestCommonAncestor.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
#include <deque>
#include <unordered_set>
#include <sstream>
#include <stack>

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(root == p || root == q || root == NULL) return root;
    	TreeNode * left = lowestCommonAncestor(root->left, p, q);
    	TreeNode * right = lowestCommonAncestor(root->right, p, q);
    	if(left && right) return root;
    	else return left? left:right;
    }
};
int main()
{
	Solution s;
	TreeNode *root = new TreeNode(3);
	TreeNode *right = new TreeNode(1);
	right->left = new TreeNode(0);
	right->right = new TreeNode(8);
	TreeNode *left = new TreeNode(5);
	left->left = new TreeNode(6);
	left->right = new TreeNode(2);
	root->left = left;
	root->right = right;
	cout<<(s.lowestCommonAncestor(root, left, right))->val<<endl;
	return 0;
}
