//============================================================================
// Name        : bfs_serializetree.cpp
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

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	queue<TreeNode*> bfs;
    	bfs.push(root);
    	string result;
    	while(!bfs.empty()){
    		TreeNode * cur = bfs.front();
    		bfs.pop();
    		result += cur? to_string(cur->val) + " ":"# ";
    		if(cur){
    			bfs.push(cur->left);
    			bfs.push(cur->right);
    		}
    	}
    	return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	istringstream in(data);
    	string val;
    	in>>val;
    	if(val == "#") return NULL;
    	TreeNode* root = new TreeNode(stoi(val));
    	queue<TreeNode*> nodeQ;
    	nodeQ.push(root);
    	while(!nodeQ.empty()){
    		TreeNode* node = nodeQ.front();
    		nodeQ.pop();
    		in>>val;
    		if(val != "#"){
    			node->left = new TreeNode(stoi(val));
    			nodeQ.push(node->left);
    		}
    		in>>val;
    		if(val != "#"){
    			node->right = new TreeNode(stoi(val));
    			nodeQ.push(node->right);
    		}
    	}
    	return root;
    }
};
int main()
{
	Codec s;
	TreeNode *node = new TreeNode(1);
	node->left = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);
	node2->left = new TreeNode(4);
	node2->right = new TreeNode(5);
	node->right = node2;
	string str = s.serialize(node);
	cout<<str<<endl;
	TreeNode* root = s.deserialize(str);
	cout<<s.serialize(root)<<endl;
	return 0;
}
