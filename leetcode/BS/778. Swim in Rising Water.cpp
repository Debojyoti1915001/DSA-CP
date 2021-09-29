// https://leetcode.com/problems/swim-in-rising-water/

Binary Search + DFS, O(n^2logn), 14ms
Binary Search range [0, n*n-1] to find the minimum feasible water level. For each water level, verification using DFS or BFS is O(n^2). DFS is slightly faster in practice.

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = grid[0][0], hi = n*n-1;
        while (low < hi) {
            int mid = low + (hi-low)/2;
            if (valid(grid, mid)) 
               hi = mid;
            else
               low = mid+1;
        }
        return low;
    }
private:
    bool valid(vector<vector<int>>& grid, int waterHeight) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<int> dir({-1, 0, 1, 0, -1});
        return dfs(grid, visited, dir, waterHeight, 0, 0, n);
    }
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, vector<int>& dir, int waterHeight, int row, int col, int n) {
        visited[row][col] = 1;
        for (int i = 0; i < 4; ++i) {
            int r = row + dir[i], c = col + dir[i+1];
            if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0 && grid[r][c] <= waterHeight) {
                if (r == n-1 && c == n-1) return true;
                if (dfs(grid, visited, dir, waterHeight, r, c, n)) return true;
            }
        }
        return false;
    }
};
Dijkstra using Priority Queue, O(n^2logn), 20 ms;
In every step, find lowest water level to move forward, so using PQ rather than queue

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        vector<int> dir({-1, 0, 1, 0, -1});
        pq.push({ans, 0, 0});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans = max(ans, cur[0]);
            for (int i = 0; i < 4; ++i) {
                int r = cur[1] + dir[i], c = cur[2] + dir[i+1];
                if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0) {
                    if (r == n-1 && c == n-1) return ans;
                    pq.push({grid[r][c], r, c});
                    visited[r][c] = 1;
                }
            }
        }
        return -1;
    }
};
Dijkstra with BFS optimization, O(n^2logn), 11 ms
Similar to above solution, but we can use BFS, which is more efficient, to expand reachable region.

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        vector<int> dir({-1, 0, 1, 0, -1});
        pq.push({ans, 0, 0});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans = max(ans, cur[0]);
            queue<pair<int, int>> myq;
            myq.push({cur[1], cur[2]});
            while (!myq.empty()) {
                auto p = myq.front();
                myq.pop();
                if (p.first == n-1 && p.second == n-1) return ans;
                for (int i = 0; i < 4; ++i) {
                    int r = p.first + dir[i], c = p.second + dir[i+1];
                    if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0) {
                        visited[r][c] = 1;
                        if (grid[r][c] <= ans) 
                           myq.push({r, c});
                        else
                           pq.push({grid[r][c], r, c});
                    }
                }
            }
        }
        return -1;
    }
};