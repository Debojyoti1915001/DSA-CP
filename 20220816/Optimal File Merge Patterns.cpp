// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    priority_queue<l,vector<l>,greater<>>pq;
    for(l i=0;i<n;i++){
        l a;
        cin>>a;
        pq.push(a);
    }
    l ans=0;
    while(pq.size()>1){
        l a=pq.top();
        pq.pop();
        l b=pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout<<ans<<endl;
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
 