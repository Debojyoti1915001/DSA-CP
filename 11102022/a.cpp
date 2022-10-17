// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    if(a[n-1]==b[m-1]){
        if(a[n-1]=='M')cout<<"="<<endl;       
        else if(a[n-1]=='S'){
            if(n>m){
                cout<<"<"<<endl;
            }else if(n<m){
                cout<<">"<<endl;
            }else{
                cout<<"="<<endl;
            }
        }else if(a[n-1]=='L'){
            if(n<m){
                cout<<"<"<<endl;
            }else if(n>m){
                cout<<">"<<endl;
            }else{
                cout<<"="<<endl;
            }
        }
    }else{
        if(a[n-1]<b[m-1]){
            cout<<">"<<endl;
        }else{
            cout<<"<"<<endl;
        }
    }
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
 