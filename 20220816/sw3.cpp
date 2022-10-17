// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l left,right;
   cin>>left>>right;
   l ans=0;

   for(l i=left;i<=(left/10+1)*10;i++){
    if(i%10==2||i%10==3||i%10==9)ans++;
   }
   for(l i=(right/10)*10;i<=right;i++){
    if(i%10==2||i%10==3||i%10==9)ans++;
   }
   ans+=(right/10-left/10-1)*3;
   cout<<ans<<endl;
}
 
int main()
{
    solve();
    return 0;
}
 