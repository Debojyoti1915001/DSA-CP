// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l int
int dfs(vector<int>& A, vector<int>& B, int i, int j, vector<vector<int>> &dp) {
  if (i >= A.size() || j >= B.size()) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  auto nj = j;
  while (nj < B.size() && B[nj] != A[i]) ++nj;
  return dp[i][j] = max(dfs(A, B, i + 1, j, dp), (nj < B.size() ? 1 : 0) + dfs(A, B, i + 1, nj + 1, dp));
}
int maxUncrossedLines(vector<int>& A, vector<int>& B) {
  vector<vector<int>> dp(A.size(), vector<int>(B.size(), -1));
  return dfs(A, B, 0, 0, dp);
}
void solve()
{
    l n,m;
    cin>>n>>m;
    vector<l>a(n),b(m);
    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;
    cout<<maxUncrossedLines(a,b)<<endl;
}
 
int main()
{
    int t = 1;
    // cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 