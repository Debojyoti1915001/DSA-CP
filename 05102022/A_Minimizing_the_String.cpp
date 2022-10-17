// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n;
   string s;
   cin>>n>>s;
   int pos=n-1;
   for(int i=0;i<n-1;i++){
    if(s[i]>s[i+1]){
        pos=i;
        break;
    }
   }
   cout<<s.substr(0,pos)+s.substr(pos+1);
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
 