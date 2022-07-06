// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<vector<l>>q;
    for(int i=0;i<n;i++){
        l a,b;
        cin>>a>>b;
        q.push_back({a,b});
    }
    vector<l>res;
    priority_queue<vector<l>>pq;//min heap
    unordered_map<l,l>m;
    l val=0;
    for(auto &i:q){
        if(i[0]==1){
            m[i[1]]++;
            pq.push({m[i[1]],val,i[1]});
        }else{
            res.push_back(pq.top()[2]);
            m[pq.top()[2]]--;
            pq.pop();
        }
        val++;
    }
    for(auto x:res)cout<<x<<" ";
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
 