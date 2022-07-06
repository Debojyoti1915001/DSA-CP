// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n,x;
   cin>>n>>x;
   vector<l>v(n);
   for(l i=0;i<n;i++)cin>>v[i];
   l j=0,i=0,sum=0;
   l ans=INT_MAX;
   while(j<n){
    sum+=v[j];
    while(i<=j&&sum>x){
        sum-=v[i];
        i++;
    }
    if(sum==x){
        ans=min(n-(j-i+1),ans);
    }
    j++;
   }
   if(ans==INT_MAX){
    cout<<-1<<endl;
   }else{
    cout<<ans<<endl;
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
 