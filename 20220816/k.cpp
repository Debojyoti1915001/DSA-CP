// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n, k;
    cin >> n >> k;
    vector<vector<l>> dp(n, vector<l>(2));
    vector<l> v(n);
    for (l i = 0; i < n; i++)
        cin >> v[i];
    dp[0][v[0] % 2] = v[0];
    for (l i = 1; i < n; i++)
    {
        if (v[i] % 2 == 0)
            dp[i][0] = dp[i - 1][0] + v[i];
        else
            dp[i][0] =max ( dp[i - 1][0] + v[i] - k,dp[i - 1][0]);
        if (v[i] % 2 == 1)
            dp[i][1] = dp[i - 1][1] + v[i];
        else
            dp[i][1] = max(dp[i - 1][1] + v[i] - k,dp[i - 1][1]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
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
