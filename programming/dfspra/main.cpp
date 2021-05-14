#include <bits/stdc++.h>
#define l long long int
using namespace std;
l N=1e+5;
int dfs(l node,l parent,l visited[],vector<l> v[]){
if(!visited[node]){
    cout<<node<<" ";
    visited[node]=1;
}
for(auto itr=v[node].begin();itr!=v[node].end();itr++){
    if(*itr!=parent)
    dfs(*itr,node,visited,v);
}
}
int main()
{
    l n;
    cin>>n;
    l visited[N]{};
vector<l> v[N];
l root;

for(l i=0;i<n-1;i++){
    l a,b;
    cin>>a>>b;
    if(i==0){
        root=a;
    }
    v[a].push_back(b);
    v[b].push_back(a);
}
dfs(root,-1,visited,v);
}
