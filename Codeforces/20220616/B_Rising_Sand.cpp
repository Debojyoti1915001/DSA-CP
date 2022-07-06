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
    if(k==1){
        if(n%2==0)
        cout<<n/2-1<<endl;
        else
        cout<<n/2<<endl;
        return;
    }
    for(l i=1;i<n-1;i++){
        if(v[i]>v[i-1]+v[i+1])ans++;
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
 