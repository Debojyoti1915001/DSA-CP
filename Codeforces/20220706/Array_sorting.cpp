// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    int n;
    cin>>n;
    vector<l>v(n);
    l ans = 0;
    for (int i = 0; i <n; i++)
    {
        cin>>v[i];
        ans = __gcd((l)ans, v[i] - i-1);
    }
    
    cout<<ans<<endl;
}
 
int main()
{
    l t = 1;
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 