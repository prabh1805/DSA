/*
* @Author: Prabhat Jha
* @Date:   2026-02-11 22:59:57
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-11 23:26:00
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};
class Solution
{
public:
	int maxDepth(TreeNode* root) {
		if (!root)return 0;
		return 1 + max(maxDepth(root -> right), maxDepth(root -> left));
	}
};
int main() {
	// Creating tree manually
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);

	Solution sol;
	cout << "Height of tree: " << sol.maxDepth(root) << endl;

}