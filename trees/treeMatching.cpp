/*
* @Author: Prabhat Jha
* @Date:   2026-02-13 02:51:54
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-13 03:21:33
* @Problem Link: https://cses.fi/problemset/task/1130
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dp;
void dfs(int node, int parent) {
	for (int child : adj[node]) {
		if (child == parent)continue;
		dfs(child, node);
		dp[node][0] += max(dp[child][0], dp[child][1]);
	}
	for (int child : adj[node]) {
		if (child == parent)continue;
		dp[node][1] = max(dp[node][1],
		                  1 + dp[child][0] + dp[node][0] - max(dp[child][0], dp[child][1])
		                 );
	}
}
int main() {
	int n;
	cin >> n;
	adj.resize(n, {});
	dp.resize(n, vector<int>(2, 0));
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1);
	cout << max(dp[0][0], dp[0][1]) << '\n';
	return 0;
}