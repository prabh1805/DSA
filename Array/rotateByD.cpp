/*
* @Author: Prabhat Jha
* @Date:   2025-06-29 01:01:15
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-06-29 01:06:24
*/
#include<iostream>
#include<vector>
using namespace std;

void rotateArr(vector<int>& arr, int d) {
	int n = (int)arr.size();
	d %= n;
	reverse(arr.begin(), arr.begin() + d);
	reverse(arr.begin() + d, arr.end());
	reverse(arr.begin(), arr.end());

}

int main() {
	vector<int> arr = { 1, 2, 3, 4, 5, 6 };
	int d = 2;

	rotateArr(arr, d);
	for (int x : arr) {
		cout << x << ' ';
	}
}