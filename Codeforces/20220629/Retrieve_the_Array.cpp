// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n  , sum = 0; cin>>n ;

    vector<l> B(n);   
    for (int i = 0; i < n; ++i) cin>>B[i], sum+= B[i];
    l sumA = sum / ( n + 1) ;

    for(int b : B){
        cout<<b - sumA<<" ";
    }
    cout<<endl;
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
 