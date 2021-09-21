#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n, m;
    cin >> n >> m;
    if (n <= m / 2 + 1)
    {
        cout << m - m / 2 - 1 << endl;
    }
    else
    {
        cout << m - n << endl;
    }
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
