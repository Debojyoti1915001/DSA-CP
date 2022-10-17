// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
vector<vector<l>>g;
vector<l>vis;
map<l,l>color;
void dfs(int i,int &cur,int cl){
    vis[i]=1;
    cur++;
    for(auto &j:g[i]){
        if(!vis[j]&&cl==color[j]){
            dfs(j,cur,cl);
        }
    }
}
void solve()
{
   l n,m;
   cin>>n>>m;
   g.resize(n+1);
   vis.resize(n+1);
   for(l i=0;i<m;i++){
    l a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }
   for(int i=1;i<=n;i++){
        l a;
        cin>>a;
        color[i]=a;
   }
   int ans=0;
   for(int i=1;i<=n;i++){
        if(!vis[i]){
            int cur=1;
            dfs(i,cur,color[i]);
            ans=max(ans,cur);
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
 