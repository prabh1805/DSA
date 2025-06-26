#include<bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using i64 = long long;
const int N = 1e5;
vector<bool> isPrime;
void seive() {
	isPrime.assign(N + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= N; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}
}
string queryPrime(int x) {
	return (isPrime[x] ? "Yes" : "No");
}

void solve() {
	int x;
	cin >> x;

	cout << queryPrime(x) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	seive();
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}