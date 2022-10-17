// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
     l n,k;
     cin>>n>>k;
     vector<l>v(n);
     l mx=0;
     for(l i=0;i<n;i++){
        cin>>v[i];
        if(v[i]>v[mx]){
            mx=i;
        }
     }
     while(k--){
        v[mx]=v[mx]*2;
     }
     l ans=0;
     for(auto &i:v)ans=ans|i;
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
 