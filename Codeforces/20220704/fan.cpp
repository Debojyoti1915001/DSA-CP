// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int

void solve()
{
   l n;
   cin>>n;
    map<l,l>dp,ans;
   for(l i=0;i<n;i++){
    l x;
    cin>>x;
    dp[x]++;
   }
   l a,b;
   cin>>a>>b;
   queue<l>q;
   q.push(0);
   l steps=0;
   while(q.size()){
    l sz=q.size();
    while(sz--){
        l t=q.front();
        q.pop();
        dp[t]++;
        ans[t]=steps;
        if(t+a<2e5+5&&!dp.count(t+a)){
            q.push(t+a);
            dp[t+a]++;
        }
        if(t-b>-2e5+5&&!dp.count(t-b)){
            q.push(t-b);
            dp[t-b]++;
        }
    }
    steps++;
   }
    l qq;
    cin>>qq;
    while(qq--){
        l k;
        cin>>k;
        if(!ans.count(k))cout<<-1<<" ";
        else
        cout<<ans[k]<<" ";
    }
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
 