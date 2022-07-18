// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<vector<int>>g(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int temp=g[i][j];
            g[i][j]=g[n-j-1][i];
            g[n-j-1][i]=g[n-i-1][n-j-1];
            g[n-i-1][n-j-1]=g[j][n-i-1];
            g[j][n-i-1]=temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<g[i][j]<<" ";
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
 