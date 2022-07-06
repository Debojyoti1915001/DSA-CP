// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   vector<vector<char>>v(8,vector<char>(8));
   for(int i=0;i<8;i++){
        string a;
        cin>>a;
        for(int j=0;j<8;j++){
            v[i][j]=a[j];
        }
   }
   int f=1;
    for(int i=1;i<7&&f;i++){
        for(int j=1;j<7&&f;j++){
            if(v[i][j]=='#'&&v[i+1][j+1]=='#'&&v[i-1][j-1]=='#'&&v[i+1][j-1]=='#'&&v[i-1][j+1]=='#'){
                cout<<i+1<<" "<<j+1<<endl;
            }
        }
    }
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
 