/*
* @Author: Prabhat Jha
* @Date:   2026-02-23 13:09:40
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-23 13:29:29
*/
/*
* @Author: Prabhat Jha
* @Date:   2026-02-23
* @Description: Print all cycles in undirected graph components
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
	int N, M;
	vector<vector<int>> adj;
	vector<bool> visited;
	vector<int> parent;

	bool dfs(int node, int par, vector<int>& cycle) {
		visited[node] = true;
		parent[node] = par;

		for (int neighbour : adj[node]) {
			if (!visited[neighbour]) {
				if (dfs(neighbour, node, cycle)) return true;
			} else if (neighbour != par) {
				// Cycle detected, trace the path
				int curr = node;
				cycle.push_back(neighbour);
				while (curr != neighbour) {
					cycle.push_back(curr);
					curr = parent[curr];
				}
				cycle.push_back(neighbour); // complete the cycle
				reverse(cycle.begin(), cycle.end());
				return true;
			}
		}
		return false;
	}

public:
	Graph(int n, int m) : N(n), M(m) {
		adj.assign(n, {});
		visited.assign(n, false);
		parent.assign(n, -1);
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u); // undirected graph
	}

	void printCycle(const vector<int>& cycle) {
		cout << "Cycle found: ";
		for (int x : cycle) cout << x << " ";
		cout << "\n";
	}

	void detectAllCycles() {
		visited.assign(N, false);
		bool anyCycle = false;

		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				vector<int> cycle;
				if (dfs(i, -1, cycle)) {
					printCycle(cycle);
					anyCycle = true;
				}
			}
		}

		if (!anyCycle) cout << "No cycles found in the graph\n";
	}
};

int main() {
	int N, M;
	cout << "Enter number of nodes and edges: ";
	cin >> N >> M;

	Graph g(N, M);
	cout << "Enter edges (0-indexed):\n";
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}

	g.detectAllCycles();

	return 0;
}