// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    string cur;
    vector<string>v;
    l k;
    while (getline(cin,cur))
    {
        v.push_back(cur);
    }
    k=stoll(v[v.size()-1]);
    v.pop_back();
    l ans=0;
    stringstream s(v[0]);
    while(s>>cur){
        l kk=k%(cur.size());
        string rev=cur.substr(kk)+cur.substr(0,kk);
        if(cur==rev)ans++;
    }
    cout<<ans;
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
