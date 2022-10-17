// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
 l n;
 cin>>n;
 if(n==2){
    cout<<2<<" "<<1<<endl;
 }else if(n==3){
    cout<<-1<<endl;
 }else{
    for(l i=n/2+1;i<=n;i++)cout<<i<<" ";
    for(l i=n/2;i>=1;i--)cout<<i<<" ";
    
    cout<<endl;
 }  
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
 