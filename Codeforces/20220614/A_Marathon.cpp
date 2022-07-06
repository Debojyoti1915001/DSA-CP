// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
l fun(l a,l b){
    if(a<b)return 1;
    return 0;
}
void solve()
{
    l a,b,c,d;
    cin>>a>>b>>c>>d;
    l ans=fun(a,b)+fun(a,c)+fun(a,d);
    cout<<ans<<endl;
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
 