/*
* @Author: Prabhat Jha
* @Date:   2025-07-01 21:59:13
* @Last Modified by:   prabhatjha
* @Last Modified time: 2025-07-01 22:46:20
*/
#include<iostream>
#include<string>
using namespace std;

void printSubSeqRec(string& s, string currSub, int index) {
	if (index == s.size()) {
		cout << currSub << '\n';
		return;
	}
	//Include current character
	printSubSeqRec(s, currSub + s[index], index + 1);
	//Don't include current character
	printSubSeqRec(s, currSub, index + 1);
}
int main() {
	string s = "ab";
	printSubSeqRec(s, "", 0);
	return 0;
}