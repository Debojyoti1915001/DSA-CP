// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    string s=to_string(n);
    sort(s.begin(),s.end());
    l p1=0,p2=0;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            p1=p1*10+(s[i]-'0');
        }else{
            p2=p2*10+(s[i]-'0');
        }
    }
    cout<<p1+p2<<endl;
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
 