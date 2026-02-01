/*
* @Author: Prabhat Jha
* @Date:   2026-02-01 23:37:15
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-02 00:35:17
* @Problem Link: https://atcoder.jp/contests/dp/tasks/dp_d
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
struct knapsack {
	int wt, val;
};

void solve() {
	int N, W;
	cin >> N >> W;
	vector<knapsack> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].wt >> arr[i].val;
	}

	// FIXED: Changed vector<i64> to vector<vector<i64>>
	vector<vector<i64>> dp(N + 1, vector<i64>(W + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= W; j++) {
			// Don't pick item i-1
			dp[i][j] = dp[i - 1][j];

			// Pick item i-1
			if (j >= arr[i - 1].wt) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i - 1].wt] + arr[i - 1].val);
			}
		}
	}
	cout << dp[N][W] << '\n';
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