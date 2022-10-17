// Debojyoti Das
//NIT Silchar
#include<bits/stdc++.h>
using namespace std;
#define l long long int
void findOrder(int n, vector<vector<int>>& p,int m) {
        //cout<<p.size()<<endl;
        queue<int>q;
        vector<int>in(n+1);
        vector<int> g[n+1];
        for(auto i:p){
            //cout<<i[0]<<" "<<i[1]<<endl;
            g[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        vector<int>res;
        for(int i=1;i<=n;i++)if(in[i]==0){
            //cout<<i<<endl;
            q.push(i);
            //res.push_back(i);
        }
        while(q.size()){
            int t=q.front();
            //cout<<t<<endl;
            res.push_back(t);
            q.pop();
            for(auto &i:g[t]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                    //res.push_back(i);
                }
            }
            
        }
        for(int i:res)cout<<i<<" ";
        // if(res.size()!=n)return {};
        // return res;
        // if(res.size()!=n)return {};
        // return res;
    }
void solve()
{
   l n,m;
   cin>>n>>m;
   vector<vector<int>>v(m,vector<int>(2));
   for(int i=0;i<m;i++){
    cin>>v[i][0];
    cin>>v[i][1];
   }
    findOrder(n,v,m);
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
 