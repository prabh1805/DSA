/*
* @Author: Prabhat Jha
* @Date:   2026-02-03 01:51:30
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-03 22:22:37
*/

#include<bits/stdc++.h>
using namespace std;

//Recursion
int countSubsetRecursive(vector<int>& nums, int n, int target) {
	if (target == 0)return 1; //Empty subset
	if (n == 0)return 0;
	if (nums[n - 1] > target) {
		return countSubsetRecursive(nums, n - 1, target);//ignore this num
	}
	int ansExcludeNum = countSubsetRecursive(nums, n - 1, target);
	int ansIncludeNum = countSubsetRecursive(nums, n - 1, target - nums[n - 1]);
	return ansExcludeNum + ansIncludeNum;
}
int countPartitionsWithDiff(vector<int>& nums, int D) {
	int total = accumulate(nums.begin(), nums.end(), 0);
	if (abs(D) > total)return 0;
	if ((total + D) % 2)return 0;

	int target = (total + D) / 2;
	return countSubsetRecursive(nums, (int)nums.size(), target);
}

//Memoization table: dp[i][j] = count of subsets using first i
//elements with sum j
vector<vector<int>> memo;

int countSubsetMemo(vector<int>& nums, int n, int target) {
	if (target == 0)return 1;
	if (n == 0)return 0;

	//Check memo
	if (memo[n][target] != -1)return memo[n][target];
	memo[n][target] = countSubsetMemo(nums, n - 1, target) +
	                  (nums[n - 1] > target ? 0 : countSubsetMemo(nums, n - 1, target - nums[n - 1]));
	return memo[n][target];
}

int countPartitionsWithMemo(vector<int>& nums, int D) {
	int n = (int)nums.size();
	int total = accumulate(nums.begin(), nums.end(), 0);
	if (abs(D) > total)return 0;
	if ((total + D) % 2)return 0;

	int target = (total + D) / 2;
	//Intialize memo
	memo.assign(n + 1, vector<int> (target + 1, - 1));
	return countSubsetMemo(nums, n, target);
}

//Tabular DP
int countPartitionsTabular(vector<int>& nums, int D) {
	int n = (int)nums.size();
	int total = accumulate(nums.begin(), nums.end(), 0);
	if (abs(D) > total || (total + D) % 2 != 0)return 0;
	int target = (total + D) / 2;

	//dp[i][j] number of ways to get sum j using i elements
	vector<vector<int>> dp(n + 1, vector<int> (target + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= target; j++) {
			//don't take nums[i - 1]
			dp[i][j] = dp[i - 1][j];
			if (nums[i - 1] <= j) {
				dp[i][j] += dp[i - 1][j - nums[i - 1]];
			}
		}
	}
	return dp[n][target];
}
//Space optimized dp
int countPartitionsTabularSpaceOptimized(vector<int>& nums, int D) {
	int n = (int)nums.size();
	int total = accumulate(nums.begin(), nums.end(), 0);
	if (abs(D) > total || (total + D) % 2 != 0)return 0;
	int target = (total + D) / 2;

	vector<int> dp(target + 1, 0);
	dp[0] = 1; //Empty subset;

	for (int num : nums) {
		for (int j = target; j >= num; j--) {
			dp[j] += dp[j - num];
		}
	}
	return dp[target];
}
10011 -
int main() {
	vector<int> nums = {1, 1, 2, 3};
	int D = 1;
	//int ans = countPartitionsWithDiff(nums, D);
	//int ans = countPartitionsWithMemo(nums, D);
	//int ans = countPartitionsTabular(nums, D);
	int ans = countPartitionsTabularSpaceOptimized(nums, D);
	cout << ans << '\n';
	return 0;
}

