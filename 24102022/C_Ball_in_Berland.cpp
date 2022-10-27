// Debojyoti Das
// NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l a, b, k;
    cin >> a >> b >> k;
    vector<pair<l,l>>edge(k);
    vector<l>cntBoys(a+1),cntGirls(b+1);
    for(auto&[x,y]:edge){
        cin>>x;
        cntBoys[x]++;
    }
    for(auto&[x,y]:edge){
        cin>>y;
        cntGirls[y]++;
    }
    l res=0;
    for(auto&[x,y]:edge){
        l noOfWaysToSelectXY=cntBoys[x]+cntGirls[y];//no considering the x and y combination
        res+=k-noOfWaysToSelectXY+1;//add the number of ways to select x and y together
    }
    cout<<res/2<<endl;
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
