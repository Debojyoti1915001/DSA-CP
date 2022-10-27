// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    string s;
    cin>>s;
    vector<vector<l>>vis(205,vector<l>(205));
    l x=100,y=100;
    for(auto &i:s){
        vis[x+1][y]++;
        vis[x][y+1]++;
        vis[x-1][y]++;
        vis[x][y-1]++;
        vis[x][y]++;
        if(i=='R')x++;
        if(i=='L')x--;
        if(i=='U')y++;
        if(i=='D')y--;
        if(vis[x][y]>=2){
            cout<<"BUG";
            return;
        }
    }
    cout<<"OK";
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
 