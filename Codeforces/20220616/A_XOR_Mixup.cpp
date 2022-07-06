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
    for(l i=0;i<n;i++){
        l x=-1;
        // cout<<"new"<<endl;
        for(l j=0;j<n;j++){
            if(j!=i){
                if(x==-1)x=v[j];
                else x^=v[j];
                // cout<<x<<"->";
            }
        }
        // cout<<x<<" "<<v[i]<<endl;
        if(x==v[i]){
            cout<<v[i]<<endl;
            return;
        }
    }
}
 
int main()
{
    int t = 1;
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
                //    cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 