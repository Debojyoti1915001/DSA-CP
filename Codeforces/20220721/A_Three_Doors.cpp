// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<l>v(4);
    for(l i=1;i<=3;i++)cin>>v[i];
    if(v[n]!=0&&v[v[n]]!=0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
 