// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<l>v(n);
    for(int i=0;i<n;i++){
        l a,b;
        cin>>a>>b>>v[i];
    }
    int ans=0;
    for(int i=1;i<n;i++){
        ans=max(ans,v[i]-v[0]);
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
 