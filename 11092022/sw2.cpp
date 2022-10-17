// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,m;
    cin>>n>>m;
    l a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    vector<l>col(m);
    vector<l>row(n);
    for(l i=0;i<n-1;i++){
        cin>>row[i];
    }
    for(l i=0;i<m-1;i++){
        cin>>col[i];
    }
    
    
    l ans=0;
    for(l i=min(a,c);i<max(a,c);i++){
        ans+=row[i];
    }
    for(l i=min(b,d);i<max(b,d);i++){
        ans+=col[i];
    }
    cout<<ans<<endl;
}
 
int main()
{
    int t = 1;
    // cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 