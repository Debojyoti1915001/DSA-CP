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
    for (auto &i : v)
        cin >> i;
    unordered_map<l,l>gcd,res;
    for(auto &i:v){
        unordered_map<l,l>gcd1;
        gcd[i]++;
        for(auto j:gcd){
            gcd1[__gcd(j.first,i)]+=j.second;
            res[__gcd(j.first,i)]+=j.second;
        }
        swap(gcd,gcd1);
    }
    l q;
    cin>>q;
    while(q--){
        l a;
        cin>>a;
        cout<<res[a]<<endl;
    }
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
