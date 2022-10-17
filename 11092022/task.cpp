// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
vector<l>dx={1,1,-1,-1};
vector<l>dy={1,-1,1,-1};
void solve()
{
   l n,m;
   cin>>n>>m;//represents the size
   l x,y;//where x,y reprents the initial position
   cin>>x>>y;
    vector<vector<l>>v(n,vector<l>(m));
    for(l i=0;i<n;i++){
        for(l j=0;j<m;j++){
            cin>>v[i][j];// let 0 mean unblocked and 1 mean blocked
        }
    }
    queue<pair<l,l>>q;
    q.push({x,y});
    v[x][y]=1;
    l ans=1;
    while(q.size()){
        auto t=q.front();
        // cout<<t.first<<" "<<t.second<<endl;
        v[t.first][t.second]=1;
        q.pop();
        ans++;
        for(l k=0;k<4;k++){
            l nx=t.first+dx[k];
            l ny=t.second+dy[k];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&v[nx][ny]==0){
                v[nx][ny]=1;
                q.push({nx,ny});
            }
        }
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
 