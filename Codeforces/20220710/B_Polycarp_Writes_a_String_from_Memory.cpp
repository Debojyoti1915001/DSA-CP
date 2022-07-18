// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   string s;
   cin>>s;
   l i=0,j=0,ans=0;
   while(i<s.size()){
        ans++;
        set<char>st;

        for(j=i;j<s.size()&&st.size()<=3;j++){
            st.insert(s[j]);
            if(st.size()==4)break;
        }
        // for(auto x:st){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // cout<<j<<endl;
        i=j;
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
 