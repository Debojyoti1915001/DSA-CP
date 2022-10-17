#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
map<ll,ll>vis;
vector<ll>alt;
void dfs2(string i,ll j){
    // cout<<i<<endl;
    if(vis[stoll(i)])return;
    vis[stoll(i)]=1;
    if(i.size()>10)return;
    alt.push_back(stoll(i));
    dfs2(i+to_string(j),j);
    if(j>0){
        dfs2(i+to_string(j-1),j-1);
    }
    if(j<9){
        dfs2(i+to_string(j+1),j+1);
    }
}
void pre(){
    for(ll i=1;i<=9;i++){
        dfs2(to_string(i),i);
    }
}
int main() {
    pre();
    ll n;
    cin>>n;
    vector<ll>ans;
    sort(alt.begin(),alt.end());
    // for(auto i:alt)cout<<i<<" ";
    while(n--){
        ll a,b;
        cin>>a>>b;
        ll cnt=0;
        ll val1=lower_bound(alt.begin(),alt.end(),a)-alt.begin();
        ll val2=upper_bound(alt.begin(),alt.end(),b)-alt.begin();
        ans.push_back(val2-val1);
    }
    for(auto &i:ans)cout<<i<<endl;
    cout<<endl;
    return 0;
}
