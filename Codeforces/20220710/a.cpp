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
    //copy from here
    vector<l>neg,pos;
    for(auto i:v){
        if(i<0){
            neg.push_back(i);
        }else{
            pos.push_back(i);
        }
    }
    for(auto x:neg){
        cout<<x<<" ";
    }    
    for(auto x:pos){
        cout<<x<<" ";
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
 