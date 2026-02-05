/*
* @Author: Prabhat Jha
* @Date:   2026-02-05 04:09:33
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-05 04:25:34
* @Problem Link: https://cses.fi/problemset/task/3403/
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
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int len = dp[n][m];
	cout << len << '\n';
	vector<int> ans;
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			ans.push_back(a[i - 1]);
			i--;
			j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		} else {
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	for (int x : ans)cout << x << " ";
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