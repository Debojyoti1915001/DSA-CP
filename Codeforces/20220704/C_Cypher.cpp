// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<l>v(n);
    for(l i=0;i<n;i++)cin>>v[i];
    for(l i=0;i<n;i++){
        l m;
        cin>>m;
        string s;
        cin>>s;
        for(l j=0;j<m;j++){
            if(s[j]=='U'){
                v[i]=v[i]-1;
                if(v[i]==-1)v[i]=9;
            }else{
                v[i]=v[i]+1;
                if(v[i]==10)v[i]=0;
            }
        }
    }
    for(auto i:v){
        cout<<i<<" ";
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
 