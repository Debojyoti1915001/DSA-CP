// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    l i=a.size()-1;
    l j=b.size()-1;
    set<char>v;
    while(i>=0){
        if(j==0){
            v.insert(a[i]);
        }
        else if(j!=0&&a[i]!=b[j]){
            cout<<"NO"<<endl;
            return;
        }else {
            j--;
        }
        i--;
    }
    if(v.count(b[0])){
        cout<<"YES"<<endl;
    }else 
    cout<<"NO"<<endl;
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
 