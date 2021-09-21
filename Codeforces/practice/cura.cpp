// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int

const l mod = 1000000007;
const l N = 3e5, M = N;

void solve()
{
    long long int x, y;
    cin >> x >> y;
    cout << max(x, y) << endl;
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
