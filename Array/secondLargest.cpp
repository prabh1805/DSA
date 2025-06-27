#include<iostream>
#include<vector>
using namespace std;

int getSecondLargest(vector<int> & arr) {
	int largest = -1, secondLargest = -1;

	for (int i : arr) {
		if (i > largest) {
			secondLargest = largest;
			largest = i;
		} else if (i < largest && i > secondLargest) {
			secondLargest = i;
		}
	}
	return secondLargest;
}
int main() {
	vector<int> arr = {12, 35, 1, 10, 34, 1};
	cout << getSecondLargest(arr);
	return 0;
}
