// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

If we pick a side of our polygon, it can form n - 2 triangles. Each such triangle forms 2 sub-polygons. We can analyze n - 2 triangles, and get the minimum score for sub-polygons using the recursion.
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286753/C%2B%2B-with-picture

Top-Down Solution
• Fix one side of the polygon i, j and move k within (i, j).
• Calculate score of the i, k, j "orange" triangle.
• Add the score of the "green" polygon i, k using recursion.
• Add the score of the "blue" polygon k, j using recursion.
• Use memoisation to remember minimum scores for each sub-polygons.

int dp[50][50] = {};
int minScoreTriangulation(vector<int>& A, int i = 0, int j = 0, int res = 0) {
  if (j == 0) j = A.size() - 1;
  if (dp[i][j] != 0) return dp[i][j];
  for (auto k = i + 1; k < j; ++k) {
    res = min(res == 0 ? INT_MAX : res, 
      minScoreTriangulation(A, i, k) + A[i] * A[k] * A[j] + minScoreTriangulation(A, k, j));
  }
  return dp[i][j] = res;
}
Bottom-Up Solution
At this point, it should not be hard to come up with a bottom-up solution. The only trick here is to move i backward. This ensures "green" and "blue" sub-polygons are processed before calculating min value for the entire polygon. It happens this way naturally with the recursive solution.

int minScoreTriangulation(vector<int>& A) {
  int dp[50][50] = {};
  for (int i = A.size() - 1; i >= 0; --i)
    for (int j = i + 1; j  < A.size();  ++j)
      for (auto k = i + 1; k < j; ++k)
        dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
  return dp[0][A.size() - 1];
} 
Complexity Analysis
Runtime: O(n ^ 3). This can be easily seen from the bottom-up solution.
Memory: O(n ^ 2). We use a square matrix to store DP results.