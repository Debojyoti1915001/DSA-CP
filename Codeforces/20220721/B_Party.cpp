// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,m;
    cin>>n>>m;
    vector<l>v(n);
    l mm=m;
    l mn=INT_MAX;
    for(l i=0;i<n;i++)cin>>v[i];
    //if m is odd you can either remove a pair
    //or we can remove a element which has odd count
    map<l,l>mp;
    while(m--){
        l a,b;
        cin>>a>>b;
        mp[a-1]++;
        mp[b-1]++;
        mn=min(mn,v[a-1]+v[b-1]);
    }
    if(mm%2==0){
        cout<<0<<endl;
    }else{
        for(auto i:mp){
            if(i.second%2==1){
                mn=min(mn,v[i.first]);
            }
        }
        cout<<mn<<endl;
    }
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
 