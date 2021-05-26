//============================================================================
// Name        : recursion_goodNodes.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
//[2,null,4,10,8,null,null,4]
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
private:
	  int helper(TreeNode* root, int curMax){
		  if(root == NULL) return 0;
		  int result = 0;
		  if(root->val >= curMax){
			  result++;
		  }
		  return result + helper(root->left, max(root->val, curMax)) + helper(root->right, max(root->val, curMax));
	  }
public:
	  int goodNodes(TreeNode* root) {
		  return helper(root, INT_MIN);
	  }
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(3, new TreeNode(1, new TreeNode(3), NULL), new TreeNode(4, new TreeNode(1), new TreeNode(5)));
	cout<<s.goodNodes(root)<<endl;
	root = new TreeNode(2, NULL, new TreeNode(4, new TreeNode(10), new TreeNode(8, new TreeNode(4), NULL)));
	cout<<s.goodNodes(root)<<endl;
	return 0;
}
