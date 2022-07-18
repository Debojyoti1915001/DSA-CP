// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<string>s;
    for(l i=0;i<n;i++){
        string a;
        cin>>a;
        s.push_back(a);
    }
    l ans=0;
    vector<vector<l>>vis(n,vector<l>(n,0));
    for(l i=0;i<n;i++){
        for(l j=0;j<n;j++){
            if(vis[i][j])continue;
            set<pair<l,l>>st;
            st.insert({i,j});
            // st.insert({n-1-i,j});
            // st.insert({i,n-1-j});
            st.insert({n-1-i,n-1-j});
            // st.insert({j,i});
            st.insert({n-1-j,i});
            st.insert({j,n-1-i});
            // st.insert({n-1-j,n-1-i});
            l z=0,o=0;
            // cout<<st.size()<<endl;
            for(auto k:st){
                vis[k.first][k.second]=1;
                if(s[k.first][k.second]=='0')z++;
                else o++;
            }
            ans+=min(z,o);
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
 