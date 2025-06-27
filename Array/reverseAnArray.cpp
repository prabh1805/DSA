#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int low = 0, high = n - 1;
	while (low < high) {
		int tmp = v[low];
		v[low] = v[high];
		v[high] = tmp;
		high--;
		low++;
	}

	for (int x : v) {
		cout << x << " ";
	}
}