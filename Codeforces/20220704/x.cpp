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
    map<l,l>m;
    for(l i=0;i<n;i++){
        cin>>v[i];
        m[v[i]]++;
    }
    l ans=0;
    sort(v.begin(),v.end());
    for(l i=0;i<n;i++){
        for(l j=i+1;j<n;j++){
            l sum=v[j]+v[i];
            l lo=0,hi=n-1;
            l cnt=0;
            while(lo<hi){
                if(v[lo]+v[hi]==sum){
                    lo++;hi--;
                    cnt++;
                }else if(v[lo]+v[hi]<sum){
                    lo++;
                }else{
                    hi--;
                }
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
}
 
int main()
{
    int t = 1;
    // cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 