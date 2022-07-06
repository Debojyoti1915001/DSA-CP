// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n;
   cin>>n;
   l a=n,b=1;
   for(l i=0;i<n;i++){
    if(i%2==0){
        cout<<a<<" ";
        a--;
    }else{
        cout<<b<<" ";
        b++;
    }
   }
   cout<<endl;
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
 