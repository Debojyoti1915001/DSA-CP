// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,k;
    cin>>n>>k;
    l ans=-1;
    for(l i=k;i<n;i++){
        l first=i;
        l second=i;
        l rest=n-first-second;
        if(rest==0){
            ans=max(ans,first*second);
        }else if(rest>0){
            if(rest%2==0){
                ans=max(ans,first*second*(l)pow(2,rest/2));
            }else{
                ans=max(ans,first*(second+1)*(l)pow(2,rest/2));
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
 