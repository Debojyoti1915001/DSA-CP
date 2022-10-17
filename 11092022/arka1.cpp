// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n,b;
   cin>>n>>b;
   l ans=0;
   l j=1;
   queue<l>q;
   q.push(0);
   while(n--){
    l sz=q.size();
    // cout<<sz<<endl;
    while(sz--){
        l t=q.front();
        q.pop();
        if(t+j!=b)
        {
            // cout<<t+j<<endl;
            ans=max(ans,t+j);
            q.push(t+j);
            q.push(t);
        }else 
            q.push(t);

    }
    j++;
   }
   cout<<ans;
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
 