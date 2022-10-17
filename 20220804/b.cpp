// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
map<string, int> m;
bool dfs(string s, l is)
{
    if (is == 0 && m.count(s) && m[s] == 1)
        return true;
    for (l i = 1; i < s.size(); i++)
    {
        string left = s.substr(0, i);
        string right = s.substr(i);
        if (m.count(left) && m[left] == 1 && dfs(right, 0))
            return true;
    }
    m[s] = 0;
    return false;
}
void solve()
{
    l n;
    cin >> n;
    vector<string> v(n);
    for (auto &i : v)
    {
        cin >> i;
        m[i] = 1;
    }
    sort(v.begin(), v.end(),[](string a,string b){
        return a.size()>b.size();
    });
    for (auto &i : v)
    {
        if (dfs(i, 1))
        {
            cout << i << " ";
            return;
        }
    }
    cout << endl;
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
