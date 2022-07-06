// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l a,b;
   cin>>a>>b;
   if(a<b){
    int req1=b-a;
    string ans;
    for(l i=0;i<a;i++)ans+="10";
    cout<<ans+string(req1,'1')<<endl;
   }else{
    int req0=a-b;
    string ans;
    for(l i=0;i<b;i++)ans+="01";
    cout<<ans+string(req0,'0')<<endl;
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
 