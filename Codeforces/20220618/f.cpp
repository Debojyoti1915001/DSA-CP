// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
  l n,q;
  cin>>n>>q;
  map<l,set<l>> v;
  for(l i=0;i<n;i++){
    l a;
    cin>>a;
    v[a].insert(i);
  }
  while(q--){
    l type,a,b;
    cin>>type>>a>>b;
    if(type==1){
        a--;
        for(l i=0;i<=100;i++){
            if(v[i].count(a)){
                auto pos=(v[i]).find(a)-v[i].begin();
                v[i].erase(pos);
                break;
            }
        }
        v[b].insert(a);
    }
    else if(type==2){
        l ans=0;
        a--;
        b--;
        for(l i=0;i<=100;i++){
            set<l>cur=v[i];
            if(cur.size()==0)continue;
            auto up=cur.upper_bound(b);
            auto lo=cur.lower_bound(a);
            if((up-lo)%2==1){
                ans++;
            }
        }
        cout<<ans<<" ";
    }
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
 