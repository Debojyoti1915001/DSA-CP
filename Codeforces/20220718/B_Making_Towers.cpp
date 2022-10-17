// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<vector<l>>dp(2,vector<l>(n+1));
    
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      dp[i & 1][x] = max(dp[i & 1][x], dp[(i ^ 1) & 1][x] + 1);
    }
 
    for (int i = 1; i <= n; i++)
      cout << max(dp[0][i], dp[1][i]) << " \n"[i == n];
 
}
 
int main()
{
    int t = 1;
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 