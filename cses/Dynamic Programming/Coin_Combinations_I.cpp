// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n,k;
   cin>>n>>k;
   l mod=1e9+7;
   vector<l>v(n);
   for(auto &i:v)cin>>i;
   vector<l>dp(k+1);
   dp[0]=1;
   for(l i=1;i<=k;i++){
    for(l j=0;j<n;j++){
        if(i>=v[j]){
            dp[i]=(dp[i]+dp[i-v[j]])%mod;
        }
    }
   }
   cout<<dp[k];
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
 