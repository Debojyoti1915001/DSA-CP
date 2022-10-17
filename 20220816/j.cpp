// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void dfs(vector<vector<l>>v,int i,l &cur,vector<l>&vis){
    if(vis[i]){
        return;
    }
    for(auto &j:v[i]){
        if(vis
        )
    }

}
void solve()
{
    l n;
    cin>>n;
    vector<l>a(n);
    vector<l>b(n);
    vector<vector<l>>v(n+1);
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        cin>>b[i];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    l m;
    cin>>m;
    while(m--){
        l i,ans=0;
        cin>>i;
        i--;
        l f=a[i];
        l s=b[i];
        v[f].erase(s);
        v[s].erase(f);
        vector<l>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cur=0;
                dfs(v,i,cur,vis);
                ans=max(ans,cur);
            }
        }
    }

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
 