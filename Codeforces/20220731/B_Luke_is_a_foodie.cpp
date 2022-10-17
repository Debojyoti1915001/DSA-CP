// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,x;
    cin>>n>>x;
    vector<l>v(n);
    for(l i=0;i<n;i++)cin>>v[i];
    
    l ans=0;
    for(l i=1;i<n;i++){
        l val=v[i]-v[i-1];
        if((val/2+val%2)>x)ans++;
    }
    cout<<ans<<endl;
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
 