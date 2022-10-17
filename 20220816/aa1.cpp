// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    map<string,unordered_set<string>>m;
    for(l i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        m[a].insert(b);
    }
    cin>>n;
    l ans=0;
    for(l i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        if(m[a].find(b)!=m[a].end()){
            ans++;
            m[a].erase(b);
        }
    }
    cout<<n-ans<<endl;
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
 