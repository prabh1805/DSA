/*
* @Author: Prabhat Jha
* @Date:   2026-02-04 03:32:47
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-04 19:39:23
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//Recursive solution
int editDistanceRecursive(string& word1, string& word2, int i, int j) {
	//Base case
	if (i == 0)return j;
	if (j == 0)return i;

	//If characters match
	if (word1[i - 1] == word2[j - 1]) {
		return editDistanceRecursive(word1, word2, i - 1, j - 1);
	}

	//If character doesn't match try all three operations
	int insertOp = editDistanceRecursive(word1, word2, i, j - 1) + 1;
	int deleteOp = editDistanceRecursive(word1, word2, i - 1, j) + 1;
	int replaceOp = editDistanceRecursive(word1, word2, i - 1, j - 1) + 1;
	return min({insertOp, deleteOp, replaceOp});
}
// Wrapper function
int minDistanceRecursive(string word1, string word2) {
	return editDistanceRecursive(word1, word2, word1.length(), word2.length());
}

//Memoization Solution
int editDistaceMemo(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
	if (i == 0)return j;
	if (j == 0)return i;

	if (memo[i][j] != -1)return memo[i][j];
	if (word1[i - 1] == word2[j - 1]) {
		memo[i][j] = editDistaceMemo(word1, word2, i - 1, j - 1, memo);
		return memo[i][j];
	}

	//If characters doesn't match
	int insertOp = editDistaceMemo(word1, word2, i, j - 1, memo) + 1;
	int deleteOp = editDistaceMemo(word1, word2, i - 1, j, memo) + 1;
	int replaceOp = editDistaceMemo(word1, word2, i - 1, j - 1, memo) + 1;

	memo[i][j] = min({insertOp, deleteOp, replaceOp});
	return memo[i][j];
}

//Wrapper function
int minDistanceMemo(string word1, string word2) {
	int m = word1.length();
	int n = word2.length();
	vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
	return editDistaceMemo(word1, word2, m, n, memo);
}

//Tabular solution
int minDistanceTabular(string& word1, string& word2) {
	int n = word1.length();
	int m = word2.length();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		dp[i][0] = i;
	}

	for (int i = 1; i <= m; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min({
					dp[i - 1][j] + 1, //Delete
					dp[i][j - 1] + 1, //Insert
					dp[i - 1][j - 1] + 1
				});
			}
		}
	}
	return dp[n][m];
}
// Space-optimized solution (O(n) space)
int minDistanceOptimized(string word1, string word2) {
	int m = word1.length();
	int n = word2.length();

	// We only need two rows at a time
	vector<int> prev(n + 1, 0);
	vector<int> curr(n + 1, 0);

	// Initialize first row
	for (int j = 0; j <= n; j++) {
		prev[j] = j;
	}

	// Fill DP table
	for (int i = 1; i <= m; i++) {
		curr[0] = i;  // Base case for first column

		for (int j = 1; j <= n; j++) {
			if (word1[i - 1] == word2[j - 1]) {
				curr[j] = prev[j - 1];
			} else {
				curr[j] = 1 + min({
					curr[j - 1],  // Insert
					prev[j],      // Delete
					prev[j - 1]   // Replace
				});
			}
		}

		// Update previous row
		prev = curr;
	}

	return prev[n];
}
int main() {
	string word1 = "horse";
	string word2 = "ros";

	cout << "String 1: " << word1 << endl;
	cout << "String 2: " << word2 << endl << endl;

	// Recursive
	cout << "Recursive solution: " << minDistanceRecursive(word1, word2) << '\n';

	//Memoization
	cout << "Memoization solution: " << minDistanceMemo(word1, word2) << '\n';

	//Tabular solution
	cout << "Tabular solution: " << minDistanceTabular(word1, word2) << '\n';

	//Tabular space optimized
	cout << "Tabular solution optimized: " << minDistanceOptimized(word1, word2) << '\n';
	return 0;
}