// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<l>a(n),b(n);
    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;
    vector<l>m;
    l ans=0;
    for(l i=0;i<n;i++){
        l cur=a[i];
        l more=m.upper_bound(cur);
        if(b[i]>=more)ans++;
        m.insert(cur);
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
 