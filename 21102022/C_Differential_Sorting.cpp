// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin >> n;
    vector<l> v(n);
    for (auto &i : v)
        cin >> i;
    if (v[n - 2] > v[n - 1])
    {
        cout << "-1" << endl;
    }
    else
    {
        if (v[n - 1] < 0)
        {
            if(is_sorted(v.begin(),v.end())){
                cout<<0<<endl;
            }else{
                cout << "-1" << endl;
            }
        }
        else
        {
            cout << n - 2 << endl;
            for (l i = 1; i <= n - 2; i++)
            {
                cout << i << " " << n - 1 << " " << n << endl;
            }
        }
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
