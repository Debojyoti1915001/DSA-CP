// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<l>v(n);
    for(auto &i:v)cin>>i;
    bool ok=true;
    for(int i=0;i<min((l)50,n);i++){
        bool notDiv=false;
        for(int j=2;j<=i+2;j++){
            if(v[i]%j!=0){
                notDiv=true;
                break;
            }
        }
        ok&=notDiv;
    }
    ok?cout<<"YES\n":cout<<"NO\n";
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
 