/*
* @Author: Prabhat Jha
* @Date:   2025-06-29 23:18:30
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-06-29 23:47:42
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int> arr = {1, 2, 3, 4, 5, 7, 9};
	int n = (int)arr.size();
	int ans = 0, cnt = 1, r = 0;
	for (int i = 1; i < n; i++) {
		if ((arr[i - 1] + arr[i]) % 2) {
			cnt++;
			if (cnt > ans) {
				r = i;
				ans = cnt;
			}
		} else {
			cnt = 1;
		}
	}
	cout << "Max length is " << ans << '\n';
	cout << "Left index is " << r - ans + 2 << " Right index is " << r + 1;
	return 0;
}