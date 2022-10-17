// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
vector<vector<l>>dp;
l fun(l i,l k,vector<l>a,vector<l>b){
    if(i<0||k<0)return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    if(k>=a[i])
    return dp[i][k]=
    max(fun(i-1,k-a[i],a,b)+b[i],fun(i-1,k,a,b));
    return dp[i][k]=
    fun(i-1,k,a,b);
    
}
void solve()
{
    l n, k;
    cin >> n >> k;
    dp.resize(n+5,vector<l>(k+5,-1));
    vector<l> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    cout<<fun(n-1,k,a,b);
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
