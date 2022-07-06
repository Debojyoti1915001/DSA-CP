// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l s;
   cin>>s;
   l x,y,z;
   cin>>x>>y>>z;
    if(s-x-y>=z){
        cout<<0<<endl;
    }else if(s-x>=z){
        cout<<1<<endl;
    }else if(s-y>=z){
        cout<<1<<endl;
    }else if(s>=z){
        cout<<2<<endl;
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
 