/*
* @Author: Prabhat Jha
* @Date:   2025-07-01 02:17:11
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-07-01 02:19:38
*/
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int maxWater(vector<int>& arr) {
	int l = 0, r = (int)arr.size() - 1, res = 0;
	while (l < r) {
		int curr = min(arr[l], arr[r]) * (r - l);
		res = max(res, curr);
		arr[r] > arr[l] ? l++ : r--;
	}
	return res;
}
int main() {
	vector<int> arr = {2, 1, 8, 6, 4, 6, 5, 5};
	cout << maxWater(arr);
	return 0;
}