// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
vector<int>ans;
vector<int>vis;
vector<int>A;
void dfs(int i,vector<int>&cur,vector<vector<int>>g){
    if(vis[i]==1)return;
    vis[i]=1;
    int sum=0;
    int more=0;
    for(auto &j:cur){
        if(j<i){
           sum+=j; 
        }
        if(A[j]>(i+1)*A[j]){
            more++;
        }
    }
    ans[i]=sum*more;
    cur.push_back(i);
    for(auto &j:g[i]){
        if(vis[j]==0){
            dfs(j,cur,g);
        }
    }
    cur.pop_back();
}
void solve()
{
    int n;
    cin>>n;
    ans.resize(n);
    vis.resize(n);
    A.resize(n);
    vector<vector<int>>g(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>cur;
   dfs(0,cur,g);
   for(auto &i:ans){
    cout<<i<<" ";
   }
   cout<<endl;
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
 