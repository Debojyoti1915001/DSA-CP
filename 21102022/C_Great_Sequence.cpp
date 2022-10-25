// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,k;
    cin>>n>>k;
    map<l,l>m;
    vector<l>v(n);
    for(l i=0;i<n;i++){
        cin>>v[i];
        m[v[i]]++;
    }
    l ans=n;
    sort(v.begin(),v.end());
    for(l i=0;i<n;i++){
        if(v[i]%k==0&&m[v[i]/k]>0){
            ans-=2;
            m[v[i]]--;
            m[v[i]/k]--;
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
 