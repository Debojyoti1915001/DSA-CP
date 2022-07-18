// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    string s;
    cin>>s;
    l ans=0;
    vector<int>cnt(26);
    for(l i=0;i<n;i++){
        if(cnt[s[i]-'A']==0)ans++;
        ans++;
        cnt[s[i]-'A']++;
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
 