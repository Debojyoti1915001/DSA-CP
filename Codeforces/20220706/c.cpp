// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve(l n,l m,vector<l>h,vector<l>v)
{
   
    //
    l mxh=1,mxv=1;
    map<l,l>hh,vv;
    for(auto i:h){
        hh[i]++;
    }
    for(auto i:v){
        vv[i]++;
    }
    //for vertical
    l cur=1;
    for(l i=1;i<=n+1;i++){
        if(vv[i]){
           cur++; 
           mxv=max(mxv,cur);
        }else{
            mxv=max(mxv,cur);
            cur=1;
        }
    }
    cur=1;
    for(l i=1;i<=m+1;i++){
        if(hh[i]){
           cur++; 
           mxh=max(mxh,cur);
        }else{
            mxh=max(mxh,cur);
            cur=1;
        }
    }
    cout<<mxv*mxh<<endl;
}
 
int main()
{
    int t = 1;
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        l n,m,a,b;
    cin>>n>>m;
    l x,y;
    cin>>x>>y;
    vector<l>h(x),v(y);
    for(l i=0;i<x;i++)cin>>h[i];
    for(l i=0;i<y;i++)cin>>v[i];
        solve(n,m,h,v);
    }
    return 0;
}
 