// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n;
   cin>>n;
   l a=0;
   for(l i=0;i<n;i++){
    l b;
    cin>>b;
    a+=b;
   }
    if(a%n)cout<<1<<endl;
    else cout<<0<<endl;
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
 
