// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin >> n;
    vector<string> a(n), b(n), ans(n,"NO");
    for (l i = 0; i < n; i++)
        cin >> a[i];
    for (l i = 0; i < n; i++)
        cin >> b[i];
    for (l i = 0; i < n; i++)
    {
        
        if (a[i] == b[i])
        {
            ans[i] = "YES";
            continue;
        }
        map<char, char> m1, m2;
        for (l j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] != b[i][j])
            {
                m1[a[i][j]] = b[i][j];
                m2[b[i][j]] = a[i][j];
            }
        }
        if (m1.size() == 1)
        {
            string cura = a[i], curb = b[i];
            for (l j = 0; j < a[i].size(); j++)
            {
                if (cura[j] != curb[j])
                {
                    if (m1.count(cura[j]))
                        cura[j] = m1[cura[j]];
                }
            }
            if (cura == curb)
                {
                    ans[i] = "YES";
                    continue;
                }
        }
        if (m2.size() == 1)
        {
            string cura = a[i], curb = b[i];
            for (l j = 0; j < a[i].size(); j++)
            {
                if (cura[j] != curb[j])
                {
                    if (m2.count(curb[j]))
                        curb[j] = m2[curb[j]];
                }
            }
            if (cura == curb)
                {
                    ans[i] = "YES";
                    continue;
                }
        }
    }
    for(auto i:ans)cout<<i<<" ";
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
