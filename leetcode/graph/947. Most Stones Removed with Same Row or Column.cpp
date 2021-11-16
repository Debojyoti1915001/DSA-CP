// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

The idea here is that we can remove all stones from the group of connected stones except the last one. Therefore, the result is the total number of stones minus the number of groups. It was tempting to solve this problem using union-find, but I wanted to play it safe and went with DFS. Afterwards, I checked the runtime of the union-find based solution, and it was the same as for DFS (20 ms).

I am using hashmaps of vectors to quickly access all occupied columns for each row, and all occupied rows for each column. Then I use DFS to group all rows connected by columns, counting the number of stones in that group.

int dfs(unordered_map<int, vector<int>> &rows, unordered_map<int, vector<int>> &cols, unordered_set<int> &v_rows, int row) {
  auto res = 0;
  if (v_rows.insert(row).second) {
    res += rows[row].size();
    for (auto c : rows[row])
      for (auto r : cols[c]) res += dfs(rows, cols, v_rows, r);
  }
  return res;
}
int removeStones(vector<vector<int>>& stones) {
  unordered_map<int, vector<int>> rows, cols;
  unordered_set<int> v_rows;
  auto res = 0;
  for (auto s : stones) rows[s[0]].push_back(s[1]), cols[s[1]].push_back(s[0]);
  for (auto r : rows) res += max(0, dfs(rows, cols, v_rows, r.first) - 1);
  return res;
}