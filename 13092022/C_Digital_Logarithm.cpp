// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<l>a(n),b(n);
    for(l i=0;i<n;i++)cin>>a[i];
    for(l i=0;i<n;i++)cin>>b[i];
    //min heap cause we want to reduce the maximum
    priority_queue<l>p(a.begin(),a.end()),q(b.begin(),b.end());
    l ans=0;
    while(p.size()){
        if(p.top()==q.top()){
            p.pop();
            q.pop();
            continue;
        }else if(p.top()>q.top()){
            l t=p.top();
            p.pop();
            p.push(to_string(t).size());
        }else{
            l t=q.top();
            q.pop();
            q.push(to_string(t).size());
        }
        ans++;
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
 