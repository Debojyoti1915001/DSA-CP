// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<l>f(n);
    for(auto &i:f){
        cin>>i;
        i--;
    }
    for(l i=0;i<n;i++){
        if(f[f[f[i]]]==i){
            cout<<"YES";
            return;
        }    
    }
    cout<<"NO";
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
 