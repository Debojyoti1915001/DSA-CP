// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,m;
    cin>>n>>m;
    l x=0,y=0,mx=INT_MIN;
    vector<vector<l>>v(n,vector<l>(m));
    for(l i=0;i<n;i++){
        for(l j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]>mx){
                mx=v[i][j];
                x=i;
                y=j;
            }
        }
    }
    cout<<max(x+1,n-x)*max(y+1,m-y)<<endl;
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
 