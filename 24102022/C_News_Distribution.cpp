// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
// l find(l x,vector<l>&parent){
//     return parent[x]==x?x:find(parent[x],parent);
// }
l dfs(vector<vector<l>>&g,l i,vector<l>&size){
    if(size[i])return 0;
    size[i]++;
    l cnt=0;
    for(l j:g[i]){
        cnt+=dfs(g,j,size);
    }
    return cnt+1;
}
void dfs2(vector<vector<l>>&g,l i,l sz,vector<l>&size,vector<l>&v){
    if(v[i]==0){
        v[i]++;
        size[i]=sz;
        for(l j:g[i]){
            dfs2(g,j,sz,size,v);
        }
    }
}
void solve()
{
   l n,m;
   cin>>n>>m;
   vector<vector<l>>g(n+1);
   for(l i=0;i<m;i++){
        l sz;
        cin>>sz;
        if(sz==0)continue;
        l first;
        cin>>first;
        for(l j=1;j<sz;j++){
            l a;
            cin>>a;
            g[first].push_back(a);
            g[a].push_back(first);
        }
   }
   vector<l>size(n+1),vis(n+1);
        for(l i=1;i<=n;i++){
            if(size[i]==0){
                size[i]=dfs(g,i,size);
                dfs2(g,i,size[i],size,vis);
            }
            cout<<size[i]<<" ";
        }
//    vector<l>parent(n+1,-1),size(n+1);
//    for(l i=1;i<=n;i++){
//     parent[i]=i;
//     size[i]++;
//    }
//    for(l i=0;i<m;i++){
//         l sz;
//         cin>>sz;
//         if(sz==0)continue;
//         map<l,l>vis;
//         l val=0;
//         l mkpar;
//         for(l j=0;j<sz;j++){
//             l a;
//             cin>>a;
//             l par=find(a,parent);
//             if(j==0)mkpar=par;
//             if(!vis[par]){
//                 vis[par]++;
//                 val+=size[par];
//             }
//             parent[a]=find(mkpar,parent);
//         }
//         size[find(mkpar,parent)]=val;
//    }
//    for(l i=1;i<=n;i++){
//     cout<<size[find(i,parent)]<<" ";
//    }

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
 