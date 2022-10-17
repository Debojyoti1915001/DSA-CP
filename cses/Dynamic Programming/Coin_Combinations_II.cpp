// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l  int
void solve()
{
    l n,k;
    cin>>n>>k;
    l mod=1e9+7;
    vector<l>v(n);
    for(auto &i:v)cin>>i;
    vector<vector<l>>dp(n+1,vector<l>(k+1));
    dp[0][0]=1;
    for(l i=1;i<=n;i++){
        for(l j=0;j<=k;j++){
            if(j>=v[i-1]){
                dp[i][j]=(dp[i-1][j]+dp[i][j-v[i-1]])%mod;
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][k];
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
 