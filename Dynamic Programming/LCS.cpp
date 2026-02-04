/*
* @Author: Prabhat Jha
* @Date:   2026-02-04 19:48:21
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-05 02:28:41
*/
#include<bits/stdc++.h>
using namespace std;

class Recursive
{
	string text1, text2;
	int len1, len2;
public:
	Recursive(string text1, string text2) : text1(text1), text2(text2) {
		this->len1 = text1.length();
		this->len2 = text2.length();
	}

	~Recursive() {}  // Empty destructor or remove it entirely

	int LCS() {
		return solve(len1, len2);
	}

private:
	int solve(int i, int j) {
		if (i == 0 || j == 0) return 0;

		// If characters match
		if (text1[i - 1] == text2[j - 1]) {
			return 1 + solve(i - 1, j - 1);
		}
		else {
			return max(
			           solve(i - 1, j),  // skip text1 character
			           solve(i, j - 1)   // skip text2 character
			       );
		}
	}
};

class Memo
{
	string text1, text2;
	int len1, len2;
public:
	Memo(string text1, string text2): text1(text1), text2(text2) {
		this -> len1 = text1.length();
		this -> len2 = text2.length();
	}

	int LCS() {
		// Create DP table with size len1 x len2
		vector<vector<int>> dp(len1, vector<int>(len2, -1));
		return solve(len1 - 1, len2 - 1, dp);
	}

	~Memo() {}

private:
	int solve(int i, int j, vector<vector<int>>& dp) {
		// Base case: if either index is negative
		if (i < 0 || j < 0) {
			return 0;
		}

		// Check if dp is already computed
		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		// Case 1: Characters match
		if (text1[i] == text2[j]) {
			dp[i][j] = 1 + solve(i - 1, j - 1, dp);
		} else {
			// Case 2: Characters don't match
			int left = (j > 0) ? solve(i, j - 1, dp) : 0;
			int top = (i > 0) ? solve(i - 1, j, dp) : 0;
			dp[i][j] = max(left, top);
		}
		return dp[i][j];
	}
};

class Tabular {
	string text1, text2;
	int len1, len2;
	vector<vector<int>> dp;  // Declare only, don't initialize yet

public:
	Tabular(string text1, string text2): text1(text1), text2(text2) {
		this->len1 = text1.length();
		this->len2 = text2.length();
		// Initialize dp AFTER len1 and len2 are known
		dp.resize(len1 + 1, vector<int>(len2 + 1, 0));
	}

	int LCS() {
		// Base cases are already initialized to 0 by resize
		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				if (text1[i - 1] == text2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[len1][len2];
	}

	string printLCS() {
		string ans = "";
		int i = len1, j = len2;

		// Reconstruct LCS from DP table
		while (i > 0 && j > 0) {
			if (text1[i - 1] == text2[j - 1]) {
				ans = text1[i - 1] + ans; // Add matching character
				i--;  // CRITICAL: Move diagonally
				j--;
			} else if (dp[i - 1][j] > dp[i][j - 1]) {
				i--;  // Move up
			} else {
				j--;  // Move left
			}
		}
		return ans;
	}

	~Tabular() {}  // Add destructor implementation

	// Optional: Print DP table for debugging
	void printDP() {
		for (int i = 0; i <= len1; i++) {
			for (int j = 0; j <= len2; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main() {
	string text1 = "photograph";
	string text2 = "tomography";
	// LCS = "tograph" (length 7)
	// Common: t o g r a p h
	//Recursive solution
	Recursive r(text1, text2);
	cout << "Recursive solution: " << r.LCS() << '\n';

	//Memoization solution
	Memo m(text1, text2);
	cout << "Memoization solution: " << m.LCS() << '\n';

	//Tabular solution
	Tabular t(text1, text2);
	cout << "Tabular solution: " << t.LCS() << "\nThe String is: " << t.printLCS() << '\n';
	return 0;
}