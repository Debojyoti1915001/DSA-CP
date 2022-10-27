// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    l ans=0;
    for(l i=0;i<n;i++){
        if(b[i]=='1'){
            if(a[i]=='0')ans++;
            else if(i-1>=0&&a[i-1]=='1')ans++;
            else if(i+1<n&&a[i+1]=='1'){
                ans++;
                a[i+1]='0';
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
 