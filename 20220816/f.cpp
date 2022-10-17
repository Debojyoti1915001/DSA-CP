// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
 l n,d;
 cin>>n>>d;
 vector<l>v(n),neg,pos;
 for(l i=0;i<n;i++){
    cin>>v[i];
 }
 l ans=0;
 sort(v.begin(),v.end());
 for(auto &i:v){
    if(i==0)ans++;
    else if(i<0){
        neg.push_back(-1*i);
    }else{
        pos.push_back(i);
    }
 }
 
  for(l i=0;i<neg.size();i++){
    if(neg[i]<=d){
        l lb=lower_bound(pos.begin(),pos.end(),d-2*neg[i])-pos.begin();
        ans=max(ans,neg.size()-i+lb-1);
    }
  }
  sort(neg.begin(),neg.end());
  for(l i=0;i<pos.size();i++){
    if(pos[i]<=d){
        l lb=lower_bound(neg.begin(),neg.end(),d-2*pos[i])-neg.begin();
        ans=max(ans,pos.size()-i+lb-1);
    }
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
 