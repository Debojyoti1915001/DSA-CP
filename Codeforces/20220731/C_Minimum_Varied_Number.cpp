#include <bits/stdc++.h>
using namespace std;
#define ll long long int

 
int main()
{
    int t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll n;
    cin>>n;
    string res;
    for(ll i=9;n!=0&&i>=1;i--){
        int minval=min(i,n);
        res+=to_string(minval);
        n=n-minval;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    }
    return 0;
}
 