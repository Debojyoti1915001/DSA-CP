// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,m,k;
    cin>>n>>m>>k;
    l c=0;
    map<l,l>mp;
    for(int i=0;i<n;i++){
        l a;
        cin>>a;
        mp[a]++;
        if(a>k)c++;
    } 
    if(k>m)
   {
       cout<<"NO"<<endl;
       return;
   }
    l cur=0,res=0;

    for(l i=0;i<k;i++){
    if(mp.count(i)){
        cur+=mp[i];
        if(i==k-1){
            res=cur+c;
        }
    }else break;
}
if(k==0)res=c;
    cout<<((res>=m)?("YES"):("NO"))<<endl;
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
 