// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   string s;
   cin>>s;
   l n=s.size();
   if(n==1){
    cout<<s<<endl;
    return;
   }
   vector<int>v(n);
   v[n-1]=s[n-1]-'0';

   for(l i=n-2;i>=0;i--){

    v[i]=min(v[i+1],s[i]-'0');
   }
   string ans;
   for(l i=0;i<n;i++){
    
    if(s[i]-'0'>v[i]){
        if((s[i]-1)!='0')
        ans+=s[i]-1;
        ans+=string(n-i-1,'9');
        break;
    }else{
        ans+=s[i];
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
 