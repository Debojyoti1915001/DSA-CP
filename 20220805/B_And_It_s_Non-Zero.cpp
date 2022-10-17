// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l a,b;
    cin>>a>>b;
    vector<l>cnt(32);
    for(l i=a;i<=b;i++){
        l cur=i;
        int j=0;
        while(cur){
            cnt[j]+=cur&1;
            cur=cur>>1;
            j++;
        }
    }
    l mn=INT_MAX;
    for(int i=0;i<=31;i++){
        mn=min(mn,b-a+1-cnt[i]);
    }
    cout<<mn<<endl;
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
 