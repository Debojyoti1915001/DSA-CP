#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int c = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int m1 = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (true)
        {
            if (pow(2, j) > v[i])
                break;
            j++;
        }
        m1 += v[i] - pow(2, j - 1);
        mx = max(mx, j - 1);
        if (v[i] != 0)
            c++;
    }
    cout << (m1 + c + mx);
}
int main()
{
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
