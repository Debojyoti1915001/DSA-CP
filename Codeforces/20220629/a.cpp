// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l ans=0;
   for(l i=0;i<n;i++){
    l mx1=0,cur1=0,mx2=0,cur2=0;
    for(int j=0;j<i;j++){
        cur1=max(v[i],v[i]+cur1);
        mx1=max(mx1,cur1);
    }
    for(int j=i;j<n;j++){
        cur2=max(v[i],v[i]+cur2);
        mx2=max(mx2,cur2);
    }
    ans=max(ans,mx1+mx2);
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
 