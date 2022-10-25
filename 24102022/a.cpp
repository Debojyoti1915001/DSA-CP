// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,retM;
    cin>>n;
    vector<l>alienList(n);
    for(auto &i:alienList)cin>>i;
    cin>>retM;
    vector<l>ans;
    sort(alienList.begin(),alienList.end(),[](l a,l b){
        if(__builtin_popcount(a)==__builtin_popcount(b))return a>b;
        return __builtin_popcount(a)>__builtin_popcount(b);
    });
    for(l i=0;i<retM;i++){
        ans.push_back(alienList[i]);
    }
    for(auto &i:ans)cout<<i<<" ";
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
 