#include<bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using i64 = long long;

vector<bool> segmentedSeive(i64 L, i64 R) {
	i64 limit = sqrt(R);
	vector<bool> mark(limit + 1, true);
	vector<i64> primes;
	for (i64 i = 2; i  <= limit; i++) {
		if (mark[i]) {
			primes.emplace_back(i);
			for (i64 j = i * i; j <= limit; j += i) {
				mark[j] = false;
			}
		}
	}
	vector<bool> isPrime(R - L + 1, true);
	for (i64 i : primes) {
		for (i64 j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
			isPrime[j - L] = false;
		}
	}
	if (L == 1)isPrime[0] = false;
	return isPrime;
}
void solve() {
	i64 L, R;
	cin >> L >> R;
	vector<bool> isPrime = segmentedSeive(L, R);

	int Q;
	cin >> Q;

	while (Q--) {
		i64 num;
		cin >> num;
		cout << (isPrime[num - L] ? "Yes" : "No") << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}