/*
* @Author: Prabhat Jha
* @Date:   2026-02-23 12:59:12
* @Last Modified by:   prabhatjha
* @Last Modified time: 2026-02-23 13:01:14
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<vector<bool>> visited;
	int n, m;
	vector<int> dx = {1, -1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};

	bool isValid(int i, int j) {
		return (i >= 0 && i < n && j >= 0 && j < m);
	}

	void dfs(int i, int j, vector<vector<char>>& grid) {
		visited[i][j] = true;
		for (int d = 0; d < 4; d++) {
			int x = i + dx[d];
			int y = j + dy[d];
			if (isValid(x, y) && !visited[x][y] && grid[x][y] == '1') {
				dfs(x, y, grid);
			}
		}
	}

	void bfs(int i, int j, vector<vector<char>>& grid) {
		visited[i][j] = true;
		queue<pair<int, int>> q;
		q.push({i, j});

		while (!q.empty()) {
			auto [a, b] = q.front();
			q.pop();

			for (int d = 0; d < 4; d++) {
				int x = a + dx[d];
				int y = b + dy[d];
				if (isValid(x, y) && !visited[x][y] && grid[x][y] == '1') {
					q.push({x, y});
					visited[x][y] = true;
				}
			}
		}
	}

public:
	int numIslandsDFS(vector<vector<char>>& grid) {
		n = grid.size();
		m = grid[0].size();
		visited.assign(n, vector<bool>(m, false));
		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && grid[i][j] == '1') {
					ans++;
					dfs(i, j, grid);
				}
			}
		}
		return ans;
	}

	int numIslandsBFS(vector<vector<char>>& grid) {
		n = grid.size();
		m = grid[0].size();
		visited.assign(n, vector<bool>(m, false));
		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && grid[i][j] == '1') {
					ans++;
					bfs(i, j, grid);
				}
			}
		}
		return ans;
	}
};

int main() {
	int n, m;
	cout << "Enter number of rows and columns: ";
	cin >> n >> m;

	vector<vector<char>> grid(n, vector<char>(m));
	cout << "Enter grid (0 for water, 1 for land):\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	Solution sol;
	cout << "\nNumber of islands (DFS): " << sol.numIslandsDFS(grid) << "\n";
	cout << "Number of islands (BFS): " << sol.numIslandsBFS(grid) << "\n";
	/*
		Sample input
		4 5
		1 1 0 0 0
		1 1 0 0 0
		0 0 1 0 0
		0 0 0 1 1
	*/
	return 0;
}