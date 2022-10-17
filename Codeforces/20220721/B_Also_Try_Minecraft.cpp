// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n,m;
   cin>>n>>m;
   vector<l>v(n);
   for(l i=0;i<n;i++)cin>>v[i];
    vector<l>left(n+1),right(n+1);
    for(l i=1;i<=n;i++){
        left[i]=left[i-1];
        if(i<n&&v[i-1]>v[i]){
            left[i]+=v[i-1]-v[i];
        }
    }
    for(l i=n-2;i>=0;i--){
        right[i+1]=right[i+2];
        if(v[i+1]>v[i]){
            right[i+1]+=v[i+1]-v[i];
        }
    }
    while(m--){
        l a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<endl;
        }else if(a<b){
            cout<<left[b-1]-left[a-1]<<endl;
        }else{
            cout<<right[b]-right[a]<<endl;
        }
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
 