// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<string>v(n);
    for(auto &i:v)cin>>i;
    l mod=1e9+7;
    if(v[n-1][n-1]=='*'){
        cout<<0;
        return;
    }
    vector<vector<l>>dp(n,vector<l>(n));
    dp[n-1][n-1]=0;
    for(l i=n-1;i>=0;i--){
        if(v[n-1][i]=='.'){
            dp[n-1][i]=1;
        }else break;
    }
    for(l i=n-1;i>=0;i--){
        if(v[i][n-1]=='.'){
            dp[i][n-1]=1;
        }else break;
    }
    for(l i=n-2;i>=0;i--){
        for(l j=n-2;j>=0;j--){
            if(v[i][j]=='*')continue;
            dp[i][j]=(dp[i+1][j]+dp[i][j+1])%mod;
        }
    }
    cout<<dp[0][0];
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
 