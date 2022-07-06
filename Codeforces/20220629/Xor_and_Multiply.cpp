// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,a,b;
    cin>>n>>a>>b;
    l res=0;
    for(l i=0;i<n;i++){
        l seti=1<<i;
        if((a^seti)*(b^seti)>a*b){
            res+=seti;
            a=a^seti;
            b=b^seti;
        }
    }
    cout<<res<<endl;
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
 