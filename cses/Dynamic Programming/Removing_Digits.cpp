// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
vector<l>dp;
// l fun(l n){
//     if(n==0)return 0;
//     if(dp[n]!=-1)return dp[n];
//     string cur=to_string(n);
//     l ans=INT_MAX;
//     for(auto &i:cur){
//         if(i!='0')
//         ans=min(ans,fun(n-(i-'0'))+1);
//     }
//     return dp[n]=ans;
// }
void solve()
{
    l n;
    cin>>n;
    dp.resize(n+1,INT_MAX);
    // cout<<fun(n);
    dp[0]=0;
    for(l i=0;i<=n;i++){
        for(auto &j:to_string(i)){
            dp[i]=min(dp[i],dp[i-(j-'0')]+1);
        }
    }
    cout<<dp[n]<<endl;
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
 