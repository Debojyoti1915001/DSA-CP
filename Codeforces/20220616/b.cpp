// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    string s;
    cin>>s;
    l c=1,j=1;
    l ans=0;
    while(j<n){
        if(s[j]!=s[j-1]){
            c++;
        }else{
            ans+=(c*(c+1))/2;
            c=1;
        }
        j++;
    }
    ans+=(c*(c+1))/2;
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
 