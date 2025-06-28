/*
* @Author: Prabhat Jha
* @Date:   2025-06-29 01:31:28
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-06-29 01:35:05
*/
#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> arr = { 16, 17, 4, 3, 5, 2 };
	int n = (int)arr.size();
	vector<int> ans;

	int curr_max = arr[n - 1];
	ans.push_back(curr_max);
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] >= curr_max) {
			curr_max = arr[i];
			ans.push_back(arr[i]);
		}
	}
	reverse(ans.begin(), ans.end());
	for (int x : arr) {
		cout << x << ' ';
	}
}