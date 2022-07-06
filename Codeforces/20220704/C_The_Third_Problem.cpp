// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
   vector<l>left,right;
   l f=0;
   for(l i=0;i<n;i++){
    l a;
    cin>>a;
    if(a==0)f=1;
    else if(f==0){
        left.push_back(a);
    }else{
        right.push_back(a);
    }
   }
   l mn=min(left.size(),right.size());
   l mx=max(left.size(),right.size());
   cout<<mn-1<<" "<<mx-1<<endl; 
}
 
int main()
{
    int t = 1;
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
                   cout<<"Case #"<<i<<": "<<endl;
        solve();
    }
    return 0;
}
 