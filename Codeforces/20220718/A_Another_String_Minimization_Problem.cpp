// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,m;
    cin>>n>>m;
    vector<l>v(n);
    for(l i=0;i<n;i++)cin>>v[i];
    string s=string(m,'B');
    for(auto &i:v){
        i--;
        if(i<m/2){
            if(s[i]=='B'){
                s[i]='A';
            }else{
                s[m-i-1]='A';
            }
        }else{
            if(s[m-i-1]=='B'){
                s[m-i-1]='A';
            }else{
                s[i]='A';
            }
        }
    }
    cout<<s<<endl;
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
 