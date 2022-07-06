// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n,f=1;
   cin>>n;
   vector<l>v(n);
   for(l i=0;i<n;i++){
    cin>>v[i];
    if(v[i]!=0)f=0;
   }
   if(f==1)cout<<"Yes"<<endl;
   else if(n==1){
    if(v[0]==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
   }
   else if(accumulate(v.begin(),v.end(),0LL)!=0)cout<<"No"<<endl;
   else if(n>1&&(v[0]<=0||v[n-1]>0)){
    cout<<"No"<<endl;
   }else if((v[1]<0&&(-1*v[0])>=v[1])||(v[n-2]>0&&(v[n-2])>=(-1*v[n-1])))  cout<<"No"<<endl;
   else cout<<"Yes"<<endl;
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
 