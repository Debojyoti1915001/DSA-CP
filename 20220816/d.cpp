// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   string s;
   l y;
   cin>>s>>y;
   l cur=0,ans=1;
   for(l i=0;i<s.size();i++){
    if(cur*10+(s[i]-'0')<y){
        cur=cur*10+(s[i]-'0');
    }else{
        ans++;
        cur=s[i]-'0';
        if(cur>y){
            cur=0;
            ans++;
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
 