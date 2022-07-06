// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
 l n,m;
 cin>>n>>m;
 for(l i=0;i<n/2;i++){
    l val=((i%2==0)?1:0);
    for(l j=0;j<m/2;j++){
        if(j%2==0)cout<<val<<" "<<1-val<<" ";
        else cout<<1-val<<" "<<val<<" ";
    }
    cout<<endl;
    for(l j=0;j<m/2;j++){
        if(j%2==0)cout<<1-val<<" "<<val<<" ";
        else cout<<val<<" "<<1-val<<" ";
    }
    cout<<endl;
 }  
}
 
int main()
{
    int t = 1;
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
                //    cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 