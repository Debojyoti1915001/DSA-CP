// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int

int dp[100005];
l check(l x,l y,vector<l>v,l i){
    if(i==v.size()){
        if(x==y)return 1;
        if(x==y)return 1;
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
    return dp[i]=(check(x+v[i],y,v,i+1)|check(x^v[i],y,v,i+1));
}
void solve()
{
    l n,x,y;
    memset(dp,-1,sizeof(dp));
    cin>>n>>x>>y;
    vector<l>v(n);
    for(l i=0;i<n;i++)cin>>v[i];
    //alice x bob x+3
    if(check(x,y,v,0)>=0)cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
