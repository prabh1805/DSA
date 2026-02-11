/*
* @Author: Prabhat Jha
* @Date:   2026-02-12 00:32:14
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-12 00:51:23
*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution
{
private:
	int dfs(Node* node) {
		if (!node)return 0;
		int ans = 0;
		for (auto child : node -> children) {
			ans = max(ans, dfs(child));
		}
		return 1 + ans;
	}
public:
	int maxDepth(Node* root) {
		return dfs(root);
	}
};

int height(int node, int parent, vector<vector<int>>& adj) {
	int ans = 0;
	for (int child : adj[node]) {
		if (child == parent)continue;
		ans = max(ans, height(child, node, adj));
	}
	return 1 + ans;
}

int main() {
	Node* root = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);
	Node* node6 = new Node(6);

	root->children = {node2, node3, node4};
	node3->children = {node5, node6};
	Solution s;
	cout << "Height (nodes): " << s.maxDepth(root) << endl;

	//Adj matrix
	int n = 6;
	vector<vector<int>> adj(n + 1);

	// edges
	adj[1].push_back(2);
	adj[2].push_back(1);

	adj[1].push_back(3);
	adj[3].push_back(1);

	adj[1].push_back(4);
	adj[4].push_back(1);

	adj[3].push_back(5);
	adj[5].push_back(3);

	adj[3].push_back(6);
	adj[6].push_back(3);

	cout << "Height (nodes): " << height(1, -1, adj) << endl;
	return 0;
}