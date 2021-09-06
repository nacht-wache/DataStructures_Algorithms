#include <cassert>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
 public:
  static TreeNode *searchBST(TreeNode *root, int val) {
	while (true) {
	  if (root == nullptr)
		return nullptr;
	  else if (val < root->val)
		root = root->left;
	  else if (val > root->val)
		root = root->right;
	  else {
		assert(root->val == val);
		return root;
	  }
	}
  }
};
