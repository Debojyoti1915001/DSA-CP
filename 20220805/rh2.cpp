// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,k;
    cin>>n>>k;
    l res=0;
    vector<l>v(n),ans;
    for(l i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    for(l j:v){
        if(ans.size()&&j-ans[0]>=k){
            ans.erase(ans.begin());
            res++;
        }
        else ans.push_back(j);
    }
    cout<<res<<endl;
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
 