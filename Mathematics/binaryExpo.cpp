#include<bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using i64 = long long;
const int MOD = 1e9 + 7;
i64 binaryExpo(i64 a, i64 b, i64 m) {
	a %= m;
	i64 res = 1;
	while (b > 0) {
		if (b & 1) {
			res = res * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	i64 a, b;
	cin >> a >> b;

	cout << binaryExpo(a, b, MOD);
	return 0;
}