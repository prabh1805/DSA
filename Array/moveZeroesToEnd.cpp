/*
* @Author: Prabhat Jha
* @Date:   2025-06-28 20:45:08
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-06-28 20:48:48
*/
#include<iostream>
#include<vector>
using namespace std;

void pushZeroToEnd(vector<int> & arr) {
	int n = (int)arr.size();
	int indx = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			swap(arr[i], arr[indx++]);
		}
	}
}
int main() {
	vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
	pushZeroToEnd(arr);
	for (int x : arr) {
		cout << x << " ";
	}
	return 0;
}