/*
* @Author: Prabhat Jha
* @Date:   2025-06-29 20:30:28
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-06-29 21:00:02
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int kadanes(vector<int>& arr, int n) {
	int ans = arr[0], sum = 0;
	for (int x : arr) {
		sum += x;
		ans = max(ans, sum);
		sum = max(sum, 0);
	}
	return ans;
}
int main() {
	vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int maxSum = kadanes(arr, (int)arr.size());
	cout << maxSum << '\n';
	return 0;
}