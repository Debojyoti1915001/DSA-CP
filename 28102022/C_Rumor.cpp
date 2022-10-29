// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
l dfs(vector<vector<l>>&g,vector<l>&v,l i){
    if(v[i]==-1)return INT_MAX;
    l mn=v[i];
    v[i]=-1;
    for(auto &j:g[i]){
        if(v[j]!=-1)
        mn=min(mn,dfs(g,v,j));
    }
    return mn;
}
void solve()
{
    l n,m;
    cin>>n>>m;
    vector<l>v(n);
    for(auto &i:v)cin>>i;
    vector<vector<l>>g(n);
    for(l i=0;i<m;i++){
        l a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    l ans=0;
    for(l i=0;i<n;i++){
        if(v[i]!=-1){
            ans+=dfs(g,v,i);
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
 