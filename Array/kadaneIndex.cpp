/*
* @Author: Prabhat Jha
* @Date:   2025-06-29 21:02:40
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-06-29 21:09:43
*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int main() {
	vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = (int)arr.size();
	int ans = arr[0], l = 0, r = 0;
	int sum = 0, minus_pos = -1;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum > ans) {
			ans = sum;
			l = minus_pos + 1;
			r = i;
		}
		if (sum < 0) {
			sum = 0;
			minus_pos = i;
		}
	}
	cout << "Maximum sum " << ans << '\n';
	cout << "left index " << l + 1 << " right index " << r + 1 << '\n';
	return 0;
}