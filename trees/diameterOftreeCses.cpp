/*
* @Author: Prabhat Jha
* @Date:   2026-02-13 01:28:34
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-13 02:51:45
* @Problem Link: https://cses.fi/problemset/task/1131
*/
#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

using i64 = long long;

#ifdef LOCAL
#include <debug.h>  // System-wide include
#else
#define dbg(...) 42
#endif

vector<vector<int>> adj;
vector<int> height, diameter;

void dfs(int node, int par) {
	int max1 = 0, max2 = 0;
	int bestChildDiameter = 0;

	for (int child : adj[node]) {
		if (child == par)continue;
		dfs(child, node);

		//since dfs on child is complete
		//lets update child diameter
		bestChildDiameter = max(bestChildDiameter, diameter[child]);

		int h = height[child];
		if (h > max1) {
			max2 = max1;
			max1 = h;
		} else if (h > max2) {
			max2 = h;
		}
	}
	//compute height of node
	height[node] = 1 + max1;
	diameter[node] = max(max1 + max2, bestChildDiameter);
}
void solve() {
	int n;
	cin >> n;
	adj.assign(n, {});
	height.assign(n, 0);
	diameter.assign(n, 0);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1);
	cout << diameter[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}