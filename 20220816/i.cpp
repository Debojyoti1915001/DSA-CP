// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    unordered_map<string,l>vis;
    unordered_map<vector<string>>m;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    string s;
    cin>>s;
    queue<string>q;
    q.push_back(s);
    while(q.size()){
        int sz=q.size();
        while(sz--){
            string t=q.front();
            q.pop();
            if(vis[t])continue;
            vis[t]++;
            cout<<t<" ";
            while(auto &i:m[t]){
                q.push(i);
            }
        }
    }
    cout<<endl;
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
 