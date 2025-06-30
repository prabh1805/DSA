/*
* @Author: Prabhat Jha
* @Date:   2025-06-30 23:28:30
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-06-30 23:39:37
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxCircularSubarraySum(vector<int>& arr) {
	int totalSum = 0;
	int maxCurrSum = 0, maxSum = arr[0];
	int minCurrSum = 0, minSum = arr[0];
	for (int x : arr) {
		totalSum += x;
		maxCurrSum = max(maxCurrSum + x, x);
		maxSum = max(maxSum, maxCurrSum);

		minCurrSum = min(minCurrSum + x, x);
		minSum = min(minSum, minCurrSum);
	}
	if (minSum == totalSum)return maxSum;
	return max(totalSum - minSum, maxSum);
}
int main() {
	vector<int> arr1 = {8, -8, 9, -9, 10, -11, 12}; // Example from explanation
	cout << "Max Circular Subarray Sum for arr1: " << maxCircularSubarraySum(arr1) << endl; // Expected: 22 (12 + 8 + -8 + 9)

	vector<int> arr2 = {1, 2, 3, -4, 5};
	cout << "Max Circular Subarray Sum for arr2: " << maxCircularSubarraySum(arr2) << endl; // Expected: 7 (5 + 1 + 2 + 3 - 4 = 7, or 1+2+3=6, or 5+1+2=8 - but wait... 1+2+3=6, 5. So 1+2+3=6. 1+2+3-4+5 = 7. max normal is 1+2+3 = 6 or 5. 5 is max. So max is 7. Total Sum = 7. Min subarray = -4. 7 - (-4) = 11. Max normal is 7. So max(7,11) = 11. Oh, example is {1,2,3,-4,5} normal max is 1+2+3 = 6. min = -4. total = 7. 7 - (-4) = 11. So it is 11 indeed)

	vector<int> arr3 = { -1, -2, -3}; // All negative numbers
	cout << "Max Circular Subarray Sum for arr3: " << maxCircularSubarraySum(arr3) << endl; // Expected: -1

	vector<int> arr4 = {5, -3, 5};
	cout << "Max Circular Subarray Sum for arr4: " << maxCircularSubarraySum(arr4) << endl; // Expected: 10 (5 + 5)

	vector<int> arr5 = {10, -4, -5, -6, 20};
	cout << "Max Circular Subarray Sum for arr5: " << maxCircularSubarraySum(arr5) << endl; // Expected: 30 (10 + 20)

	vector<int> arr6 = {3, -2, -1, 4};
	cout << "Max Circular Subarray Sum for arr6: " << maxCircularSubarraySum(arr6) << std::endl; // Expected: 7 (4+3)

	return 0;
}