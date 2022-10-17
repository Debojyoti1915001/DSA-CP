// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
bool dfs(l i,vector<l>&v,vector<l>&vis){
    if(i>=v.size())return true;
    if(i<0)return false;
    
}
void solve()
{
   l n;
   cin>>n;
   vector<l>v(n),vis(n);
   for(auto &i:v)cin>>i;
   for(l i=0;i<n;i++){
    if(!vis[i]){
        if(dfs(i,v,vis)){
            cout<<i<<endl;
            return;
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
 