/*
* @Author: Prabhat Jha
* @Date:   2025-06-29 23:13:34
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-06-29 23:17:43
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& arr, int n) {
	int ans = 0, count = 1;
	for (int i = 1; i < n; i++) {
		if ((arr[i - 1] + arr[i]) % 2) {
			count++;
			ans = max(ans, count);
		} else {
			count = 1;
		}
	}
	return ans;
}
int main() {
	vector<int> arr = {1, 2, 3, 4, 5, 7, 9};
	int ans = solve(arr, (int)arr.size());
	cout << ans << '\n';
	return 0;
}