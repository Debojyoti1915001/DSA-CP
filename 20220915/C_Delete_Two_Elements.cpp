// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin >> n;
    vector<l> v(n);
    map<l,l>m;
    for (auto &i : v)
    {
        cin >> i;
        m[i]++;
    }
    l sum=accumulate(v.begin(),v.end(),0LL);
    if((2*sum)%n){
        cout<<0<<endl;
        return;
    }
    l req=2*sum/n;
    l ans=0;
    for (auto &i : v)
    {
        m[i]--;
        ans+=m[req-i];
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
