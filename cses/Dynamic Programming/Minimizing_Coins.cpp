// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n, target;
    cin >> n >> target;
    vector<l> v(n);
    for (auto &i : v)
        cin >> i;

    vector<l> dp(target + 1, INT_MAX);
    dp[0] = 0;//if target is 0
    for (l i = 1; i <= target; i++)
    {
        for (l j = 0; j < n; j++)
        {
            if (i >= v[j])
            {
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }
    cout << (dp[target] == INT_MAX ? -1 : dp[target]);
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
