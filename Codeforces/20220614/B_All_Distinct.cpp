// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    unordered_map<l,l>m;
    for(l i=0;i<n;i++){
        l a;
        cin>>a;
        m[a]++;
    }
    l o=0,e=0;
    for(auto x:m){
        if(x.second%2==0){
            e++;
        }else{
            o++;
        }
    }
    l val=(e%2==0)?(e):(e-1);
    cout<<o+val<<endl;
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
 