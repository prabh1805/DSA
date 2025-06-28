/*
* @Author: Prabhat Jha
* @Date:   2025-06-29 01:46:57
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-06-29 01:52:03
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> arr = {0, 1, 0, 1, 1, 1, 1};
	int n = (int)arr.size();
	int cnt = 0, ans = 0;
	for (int x : arr) {
		if (x) {
			cnt++;
		} else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	ans = max(ans, cnt);
	cout << ans << '\n';
	return 0;
}
