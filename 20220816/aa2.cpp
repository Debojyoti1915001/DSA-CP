// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
l fun(vector<char>v,char a,int i,int j){
    l ans=0;
    for(l k=0;k<v.size();k++){
        if(v[k]==a){
            ans+=abs(k-i);
            i++;
        }
    }
    return ans;
}
void solve()
{   
   l n;
   cin>>n;
   vector<char>v(n);
   for(auto &i:v)cin>>i;
   char a,b;
   cin>>a>>b;
   
   l sza=0,szb=0;
   for(auto i:v){
    if(i==a)sza++;
    if(i==b)szb++;
   }

   l i=0,j=0,ans=INT_MAX;
   while(j<v.size()){
    if(j-i+1<sza+szb){
        j++;
    }else{
        l vala=fun(v,a,i,i+sza-1);
        l valb=fun(v,b,i+sza,j);
        cout<<vala+valb<<endl;
        ans=min(ans,vala+valb);
        j++;i++;
    }
   }
    cout<<ans<<endl;
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
 