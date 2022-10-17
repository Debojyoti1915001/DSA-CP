// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,m;
    cin>>n>>m;
    vector<vector<l>>v(n,vector<l>(m));
    for(l i=0;i<n;i++){
        for(l j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    
    for(l i=0;i<n;i++){
        for(l j=0;j<m;j++){
            if(i==0&&j==0){
                v[i][j]=v[i][j];
            }else if(i==0){
                v[i][j]+=v[i][j-1];
            }else if(j==0){
                v[i][j]+=v[i-1][j];
            }else{
                v[i][j]=v[i][j]+v[i][j-1]+v[i-1][j]-v[i-1][j-1];
            }
        }
    }
    for(l i=0;i<n;i++){
        for(l j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
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
 