/*
* @Author: Prabhat Jha
* @Date:   2026-02-05 02:45:04
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-05 19:53:50
*/
#include <bits/stdc++.h>
using namespace std;
class Recursive
{
	string s;
	int len;
public:
	Recursive(string s) : s(s) {
		this -> len = s.length();
	}
	~Recursive() {};
	int longestPalindromeSubsequence() {
		return solve(0, len - 1);
	}
private:
	int solve(int l, int r) {
		if (l > r)return 0;
		if (l == r)return 1;

		//Case 1 : First and last character matches
		if (s[l] == s[r]) {
			return 2 + solve(l + 1, r - 1);
		} else {
			return max(solve(l + 1, r), solve(l, r - 1));
		}
	}

};

class Memo
{
	string s;
	int len;
public:
	Memo(string s): s(s) {
		this -> len = s.length();
	}
	~Memo() {};
	int longestPalindromeSubsequence() {
		vector<vector<int>> memo(len, vector<int> (len, -1));
		return solve(0, len - 1, memo);
	}
private:
	int solve(int l, int r, vector<vector<int>>& memo) {
		//Base cases
		if (l > r)return 0;
		if (l == r)return 1;

		//Check if already computed
		if (memo[l][r] != -1) {
			return memo[l][r];
		}

		//Compute and store
		if (s[l] == s[r]) {
			memo[l][r] = 2 + solve(l + 1, r - 1, memo);
		} else {
			memo[l][r] = max(
			                 solve(l + 1, r, memo),
			                 solve(l, r - 1, memo)
			             );
		}
		return memo[l][r];
	}
};

class Tabular
{
	string s;
	int n;
	vector<vector<int>> dp;
public:
	Tabular(string s): s(s) {
		this -> n = s.length();
		dp.resize(n, vector<int>(n, 0));
	}
	~Tabular() {};
	int longestPalindromeSubsequence() {
		return solve();
	}
	string printLPS() {
		return print();
	}
private:
	int solve() {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j]) {
					dp[i][j] = 2 + (j - i + 1 > 2 ? dp[i + 1][j - 1] : 0);
				} else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
	string print() {
		int i = 0, j = n - 1;
		string left = "", right = "";
		while (i < j) {
			if (s[i] == s[j]) {
				left += s[i];
				right = s[i] + right;
				i++;
				j--;
			} else if (dp[i + 1][j] > dp[i][j - 1]) {
				i++;
			} else {
				j--;
			}
		}
		if (i == j) {
			return left + s[i] + right;
		} else {
			return left + right;
		}
	}

};
int main() {
	string s = "bbbab";
	Recursive r(s);
	cout << "Recursive solution: " << r.longestPalindromeSubsequence() << '\n';

	Memo m(s);
	cout << "Memoization solution: " << m.longestPalindromeSubsequence() << '\n';

	Tabular t(s);
	cout << "Tabular solution: " << t.longestPalindromeSubsequence() << '\n';
	cout << "Palindromic Subsequnce is: " << t.printLPS() << '\n';
	return 0;
}