/*
* @Author: Prabhat Jha
* @Date:   2026-02-02 01:36:37
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-03 01:51:12
*/
#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

using i64 = long long;
const i64 INF = 1e18;

#ifdef LOCAL
#include <debug.h>  // System-wide include
#else
#define dbg(...) 42
#endif

struct knapsack
{
	int wt, val;
};
void solve() {
	int N, W;
	cin >> N >> W;
	int total_val = 0;
	vector<knapsack> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].wt >> arr[i].val;
		total_val += arr[i].val;
	}

	vector<vector<i64>> dp(N + 1, vector<i64>(total_val + 1, INF));
	dp[0][0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int value = 0; value <= total_val; value++) {
			//skip i - 1th value
			dp[i][value] = dp[i - 1][value];
			if (arr[i - 1].val <= value) {
				dp[i][value] = min(dp[i][value], dp[i - 1][value - arr[i - 1].val] + arr[i - 1].wt);
			}
		}
	}
	i64 ans = 0;
	for (int i = total_val; i >= 0; i--) {
		if (dp[N][i] <= W) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
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