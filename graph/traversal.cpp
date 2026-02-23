/*
* @Author: Prabhat Jha
* @Date:   2026-02-23 12:10:03
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-23 12:26:19
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int N, M;

//Function to perform dfs
void dfs(int node) {
	visited[node] = true;
	cout << node << " "; //process node
	for (int neighbour : adj[node]) {
		if (visited[neighbour])continue;
		dfs(neighbour);
	}
}

//Function for BFS
void bfs(int node) {
	visited[node] = true;
	queue<int> q;
	q.push(node);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		for (int neighbour : adj[curr]) {
			if (visited[neighbour])continue;
			visited[neighbour] = true;
			q.push(neighbour);
		}
	}
}

int main() {
	cout << "Enter number of nodes and edges \n";
	cin >> N >> M;
	adj.assign(N, {});

	cout << "Enter edges (u v) 0-indexed:\n";
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);  // directed graph
		adj[v].push_back(u);  // comment this line for directed graph
	}

	cout << "\nDFS Traversal starting from node 0:\n";
	visited.assign(N, false);
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(i);
			cout << "\n";
		}
	}

	cout << "\nBFS Traversal starting from node 0:\n";
	visited.assign(N, false);
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			bfs(i);
			cout << "\n";
		}
	}
	return 0;
}