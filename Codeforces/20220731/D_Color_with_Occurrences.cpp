// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll n, len;
vector<ll> dp;
string t;
vector<string> a;

ll dfs(ll idx)
{
    if (idx == len)
        return dp[idx] = 0;
    if (dp[idx] != INT_MAX)
        return dp[idx];

    ll cur = INT_MAX;

    for (auto &i:a)
        if (idx + i.length() - 1 < len && t.substr(idx,i.length()) == i)
            for (ll k = 1; k <= i.length(); k++)
            {
                cur = min(cur, 1 + dfs(idx + k));
            }

    return dp[idx] = cur;
}

void solve()
{
    cin >> t >> n;
    dp = vector<ll>(t.size() + 5, INT_MAX);
    len = t.length();

    a=vector<string>(n);
    for (string &s : a)
        cin >> s;

    ll ans = dfs(0);
    if (ans == INT_MAX)
        cout << -1 << endl;
    else
    {
        vector<vector<ll>> result;

        ll idx = 0;

        while (idx < len)
        {
            for (ll i = 0; i < n; i++)
            {
                bool f = false;
                if (idx + a[i].length() - 1 < len && t.substr(idx, a[i].length()) == a[i])
                    for (ll k = 1; k <= a[i].length(); k++)
                    {
                        if (dp[idx] == 1 + dp[idx + k])
                        {
                            f = true;
                            idx = idx + k;
                            result.push_back({i+1, idx - k+1});
                        }

                        if (f)
                            break;
                    }

                if (f)
                    break;
            }
        }
        cout<<result.size()<<endl;
        for (auto x : result)
            cout << x[0]  << ' ' << x[1]  << endl;
    }
}
 
int main()
{
    int tt = 1;
    cin >> tt;
    for (ll i = 1; i <= tt; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 