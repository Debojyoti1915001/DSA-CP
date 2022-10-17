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
    for (l i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    // pre[0]=v[0];
    // for(l i=1;i<n;i++){
    //     pre[i]+=pre[i-1]+v[i];
    // }
    l m;
    cin>>m;
    while(m--){
        l a,b;
        cin>>a>>b;
        l i=lower_bound(v.begin(),v.end(),a)-v.begin();
        l j=lower_bound(v.begin(),v.end(),b)-v.begin(); 
        cout<<j-i+1<<endl;
    }
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
