// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<string>v;
    unordered_map<string,int>m;
    for(l i=0;i<n;i++){
        string a;
        cin>>a;
        v.push_back(a);
        m[a]++;
    }
    for(l i=0;i<n;i++){
        string cur=v[i];
        l f=0;
        for(l j=1;j<cur.size();j++){
            if(m[cur.substr(0,j)]&&m[cur.substr(j)]){
                cout<<1;
                f=1;
                break;
            }
        }
        if(!f)cout<<0;
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
 