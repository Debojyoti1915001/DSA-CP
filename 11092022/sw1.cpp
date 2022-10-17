// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   map<string,int>m;
   l n;
   cin>>n;
   vector<string>v(n),ans;
   for(auto &i:v){
    cin>>i;
    if(!m.count(i)){
        ans.push_back(i);
    }else{
        ans.push_back(i+to_string(m[i]));
    }
    m[i]++;
   }
   for(auto &i:ans)cout<<i<<" ";
}
 
int main()
{
    int t = 1;
    // cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 