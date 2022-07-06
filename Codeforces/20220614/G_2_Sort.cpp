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
    l ans=0;
    for(l i=0;i<n;i++)cin>>v[i];
    l c=0;
    for(l i=1;i<n;i++){
        if(v[i-1]<v[i]*2){
            c++;
            if(c>=k)ans++;
        }else{
            c=0;
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
 