// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
vector<l>dp;
l check(vector<pair<l,l>>v,map<l,l>&dp1,map<l,l>&dp2,l i){
    for(auto x:dp){
        cout<<x<<" ";
    }
    cout<<endl;
    if(i==v.size()){
        return true;
    }
    if(dp[i]!=-1)return dp[i];
    l a=v[i].first;
    l b=v[i].second;
    if((!dp1.count(a))&&(!dp1.count(b))&&(!dp2.count(a))&&(!dp2.count(b))){
        dp1[a]++;
        dp1[b]++;
        if(check(v,dp1,dp2,i+1))return dp[i]=1;
        dp1.erase(a);
        dp1.erase(b);
        dp2[a]++;
        dp2[b]++;
        if(check(v,dp1,dp2,i+1))return dp[i]=1;
        dp2.erase(a);
        dp2.erase(b);
    }else if((dp1.count(a)||dp1.count(b))&&((!dp2.count(a))&&(!dp2.count(b)))){
        dp2[a]++;
        dp2[b]++;
        if(check(v,dp1,dp2,i+1))return dp[i]=1;
        dp2.erase(a);
        dp2.erase(b);
    }
    else if((dp2.count(a)||dp2.count(b))&&((!dp1.count(a))&&(!dp1.count(b)))){
        dp1[a]++;
        dp1[b]++;
        if(check(v,dp1,dp2,i+1))return dp[i]=1;
        dp1.erase(a);
        dp1.erase(b);
    }else{ return dp[i]=0;}
}
void solve()
{
    l n;
    cin>>n;
    dp=vector<l>(n,-1);
    map<l,l>dp1,dp2;
    vector<pair<l,l>>v;
    for(l i=0;i<n;i++){
        l a,b;
        cin>>a>>b;
        if(a<b)
        v.push_back({a,b});
        else
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    // cout<<check(v,dp1,dp2,0)<<endl;
    if(check(v,dp1,dp2,0))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
 