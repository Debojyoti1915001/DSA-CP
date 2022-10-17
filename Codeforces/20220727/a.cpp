// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n,x;
   cin>>n;
   vector<l>v(n);
   for(l i=0;i<n;i++)cin>>v[i];
   cin>>x;
   priority_queue<l,vector<l>,greater<>>pq;
   for(auto i:v)pq.push(i);
   string cur,mx=to_string(x);
   vector<l>lastlen;
   l ans=0;
   while(pq.size()){
    // cout<<cur+to_string(pq.top())<<" "<<x<<" ";
    while(cur+to_string(pq.top())>mx&&lastlen.size()){
        l len=cur.size();
        // cout<<"yes x ";
        cur=cur.substr(len-lastlen.back(),len);
        lastlen.pop_back();
    }
    if(cur+to_string(pq.top())<=mx){
        cur+=to_string(pq.top());
        // cout<<"yes y ";
        ans=max(ans,(l)cur.size());
        lastlen.push_back(to_string(pq.top()).size());
    }
     pq.pop();
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
 