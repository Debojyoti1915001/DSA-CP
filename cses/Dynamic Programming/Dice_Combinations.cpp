// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    l mod=1e9+7;
    vector<l>dp(n+1);
    dp[0]=1;
    for(l i=1;i<=n;i++){
        for(l j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
    }
    // for(auto &i:dp)cout<<i<<" ";
    cout<<dp[n];
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
 