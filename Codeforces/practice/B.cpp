#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<string> v;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    string val;
    cin >> val;
    map<char, int> m;
    for (int i = 0; i < val.length(); i++)
    {
        m[val[i]] = i;
    }
    string ans = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        int k = 0, f = 0;
        while (k < min(ans.length(), v[i].length()))
        {
            if (m[ans[k]] < m[v[i][k]])
            {
                ans = v[i];
                f = 1;
                break;
            }
            k++;
        }
        if (f == 0)
        {
            if (v[i].length() > ans.length())
            {
                ans = v[i];
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    int t = 1;
    for (int i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
