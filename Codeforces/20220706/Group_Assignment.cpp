// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   unordered_map<l,l>m;
   l n;
   cin>>n;
   for(l i=0;i<n;i++){
    l a;
    cin>>a;
    m[a]++;
   }
   for(auto a: m){
        if(a.second%a.first!=0){
            cout<<"NO"<<endl;
            return;
        }
   }
   cout<<"YES"<<endl;
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
 