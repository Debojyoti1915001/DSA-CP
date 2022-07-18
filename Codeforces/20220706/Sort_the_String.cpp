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
    l last=n-1;
    for(last=n-1;last>=0;last--){
        if(s[last]=='0')break;
    }
    for(l i=last;i>=0;i--){
        if(s[i]=='1')ans++;
        while(i>0&&s[i]==s[i-1])i--;
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
 