// This question can be solved using bfs. The obstacle make the visited matrix to be 3D.
// visited[][][0~k], the third index i means if we remove i obstacle, whether the grid is visited. The states are (i, j, k), where k is the number of obstacle removed. Space is visited matrix MNK, time is MNK

class Solution {
public:

	vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	int shortestPath(vector<vector<int>>& grid, int k) {
		int m = grid.size(), n = grid[0].size();
		queue<vector<int>> q;
		int step = 0;
		vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
		if (grid[0][0] == 1) { 
			q.push({0, 0, 1});
			visited[0][0][1] = true;
		}
		else { 
			q.push({0, 0, 0});
			visited[0][0][0] = true;
		}

		while (!q.empty()) { 
			int l = q.size();
			for (int i = 0; i < l; i++) { 
				vector<int> s = q.front();
				q.pop();
				if (s[2] == k + 1) { 
					continue;
				}

				if (s[0] == m - 1 && s[1] == n - 1) { 
					return step;
				}

				for (vector<int>& dir : dirs) { 
					int new_x = s[0] + dir[0];
					int new_y = s[1] + dir[1];
					//Note: validity, visited
					if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) { 
						if (grid[new_x][new_y] == 0 && !visited[new_x][new_y][s[2]]) { 
							q.push({new_x, new_y, s[2]});
							visited[new_x][new_y][s[2]] = true;
						}
						else if (grid[new_x][new_y] == 1 && !visited[new_x][new_y][s[2] + 1]){ 
							q.push({new_x, new_y, s[2] + 1});
							visited[new_x][new_y][s[2] + 1] = true;
						}
					}
				}
			}
			step++;
		}
		return -1;

	}
};