// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n;
   cin>>n;
   if(n%2==0){
    cout<<n/2;
   }else{
    l d=-1;
    for(l i=3;i<=sqrt(n);i+=2){
        if(n%i==0){
            d=i;
            break;
        }
    }
    if(d==-1){
        cout<<1;
    }else{
        cout<<1+(n-d)/2;
    }
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
 