// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
bool valid(vector<l>v,l c,l val){
    l count=1,lastpos=v[0];
    for(l i=1;i<v.size();i++){
        if(v[i]-lastpos>=val){
            count++;
            if(count==c)return true;
            lastpos=v[i];
        }
    }
    return false;
}
void solve()
{
    l n,c,res=-1;
    cin>>n>>c;
    vector<l>v(n);
    for(l i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    l lo=0,hi=v[n-1];
    while(lo<=hi){
        l mid=lo+(hi-lo)/2;
        if(valid(v,c,mid)){
            res=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
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
