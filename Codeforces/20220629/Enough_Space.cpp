// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,x,y;
    cin>>n>>x>>y;
    if(n-x-2*y>=0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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
 