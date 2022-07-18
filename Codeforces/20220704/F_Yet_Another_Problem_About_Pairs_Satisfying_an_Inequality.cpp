// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<pair<l,l>>v;
    l cur=0;
    for(l i=1;i<=n;i++){
        l a;
        cin>>a;
        if(a<i){
            v.push_back({a,i});
        }
    }
    l ans=0;
    vector<l>dp;
    for(l i=0;i<v.size();i++){
        l idx=lower_bound(dp.begin(),dp.end(),v[i].first)-dp.begin();
        ans+=idx;
        dp.push_back(v[i].second);
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
 