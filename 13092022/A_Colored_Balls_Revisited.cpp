// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    l mx=0,ans=0;
    for(l i=0;i<n;i++){
        l t;
        cin>>t;
        if(t>=mx){
            mx=t;
            ans=i+1;
        }    
    }
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
 