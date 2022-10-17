// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,k;
    cin>>n>>k;
    vector<pair<l,l>>v;
    for(l i=1;i<=n;i+=2){
        l a=i,b=i+1;
        if(((a+k)*b)%4==0){
            v.push_back({a,b});
        }else if(((b+k)*a)%4==0){
            v.push_back({b,a});
        }else {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(auto &i:v){
        cout<<i.first<<" "<<i.second<<endl;
    }
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
 