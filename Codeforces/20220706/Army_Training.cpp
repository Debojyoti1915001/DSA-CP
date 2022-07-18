// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define li long long int
void solve(){
    li n,mx=0,l=0,r=0;
    cin>>n;    
    vector<li>v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
        r+=v[i];
    }
    sort(begin(v),end(v));
    for(int i=0;i<n;i++){
        r-=v[i];
        l+=1000-v[i];
        mx=max(mx,l*r);
    }
    cout<<mx<<"\n";
}

int main()
{
    int t = 1;
    cin >> t;
    for (li i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
