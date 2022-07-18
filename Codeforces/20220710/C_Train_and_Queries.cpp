// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    unordered_map<l,l>mn,mx;
    l n,q;
    cin>>n>>q;
    for(l i=1;i<=n;i++){
        l a;
        cin>>a;
        if(mn.count(a))
        mn[a]=min(mn[a],i);
        else mn[a]=i;
        mx[a]=max(mx[a],i);
    }
    while(q--){
        l a,b;
        cin>>a>>b;
        // cout<<"a "<<mn[a]<<" "<<"b "<<mn[b]<<endl;
        if(mn.count(a)&&mn.count(b)&&mn[a]<mx[b]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    // cout<<endl;
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
 