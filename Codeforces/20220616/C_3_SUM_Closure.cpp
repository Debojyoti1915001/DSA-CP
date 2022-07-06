// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n;
   cin>>n;
   vector<l>v(n);
   for(l i=0;i<n;i++)cin>>v[i];
   map<l,l>m;
   for(auto x:v){
        m[x]++;
   }
    if(m[0]==n){
        cout<<"YES"<<endl;
    }else if(n==3){
        if(m.count(v[0]+v[1]+v[2])){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;    
        }
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
 