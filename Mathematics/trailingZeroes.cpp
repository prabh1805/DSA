#include<bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	int ans = 0;
	for (int i = 5 ; i <= n; i++) {
		ans += n / i;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}