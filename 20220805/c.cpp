// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n;
   cin>>n;
   vector<l>v(n);
   for(l i=0;i<n;i++)cin>>v[i];
   vector<l>left(n+2),right(n+2);
   left[0]=0;
   for(int i=1;i<=n;i++)left[i]=max(left[i-1],v[i-1]);
    right[n]=0;
    for(int i=n;i>0;i--)right[i]=max(right[i+1],v[i-1]);
    l q;
    cin>>q;
    vector<l>res;
    while(q--){
        l N;
        cin>>N;
        l ans=0;
        for(l i=N;i<n;i++){
            ans+=max(left[i],right[i]);
        }
        res.push_back(ans);
    }
    for(auto &i:res)cout<<i<<" ";
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
 