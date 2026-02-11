/*
* @Author: Prabhat Jha
* @Date:   2026-02-12 00:57:45
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-12 01:15:45
*/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> parent;

//DFS to find the farthest node
pair<int, int> dfs(int node, int par, int depth) {
	parent[node] = par;
	pair<int, int> res = {depth, node};

	for (int child : adj[node]) {
		if (child == par)continue;
		res = max(res, dfs(child, node, depth + 1));
	}
	return res;
}
//BFS to find farthest node
pair<int, int> bfs(int start) {
	vector<int> dist(n + 1, -1);
	queue<int> q;

	q.push(start);
	dist[start] = 0;
	parent[start] = -1;

	int farthest_node = start;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int child : adj[node]) {
			if (dist[child] == -1) {
				dist[child] = dist[node] + 1;
				parent[child] = node;
				q.push(child);

				if (dist[child] > dist[farthest_node]) {
					farthest_node = child;
				}
			}
		}
	}

	return {dist[farthest_node], farthest_node};
}

int main() {

	n = 6;
	adj.resize(n + 1);
	parent.resize(n + 1);

	vector<pair<int, int>> edges = {
		{1, 2},
		{2, 3},
		{3, 4},
		{2, 5},
		{5, 6}
	};

	for (auto e : edges) {
		adj[e.first].push_back(e.second);
		adj[e.second].push_back(e.first);
	}

	cout << "---- USING DFS ----" << endl;

	// First DFS
	auto first_dfs = dfs(1, -1, 0);

	// Second DFS
	auto second_dfs = dfs(first_dfs.second, -1, 0);

	cout << "Diameter (edges): " << second_dfs.first << endl;
	cout << "Diameter (nodes): " << second_dfs.first + 1 << endl;

	// Reconstruct path (DFS)
	vector<int> path_dfs;
	int curr = second_dfs.second;

	while (curr != -1) {
		path_dfs.push_back(curr);
		curr = parent[curr];
	}

	reverse(path_dfs.begin(), path_dfs.end());

	cout << "Diameter Path (DFS): ";
	for (int node : path_dfs)
		cout << node << " ";
	cout << endl;


	cout << "\n---- USING BFS ----" << endl;

	// First BFS
	auto first_bfs = bfs(1);

	// Second BFS
	auto second_bfs = bfs(first_bfs.second);

	cout << "Diameter (edges): " << second_bfs.first << endl;
	cout << "Diameter (nodes): " << second_bfs.first + 1 << endl;

	// Reconstruct path (BFS)
	vector<int> path_bfs;
	curr = second_bfs.second;

	while (curr != -1) {
		path_bfs.push_back(curr);
		curr = parent[curr];
	}

	reverse(path_bfs.begin(), path_bfs.end());

	cout << "Diameter Path (BFS): ";
	for (int node : path_bfs)
		cout << node << " ";
	cout << endl;

	return 0;
}
