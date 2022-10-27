// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    //if there is both '<' and '>' present then we can't complete one full cycle 
    l n;
    cin>>n;
    bool o=false,c=false;
    string s;
    cin>>s;
    l res=0;
    s+=s[0];
    for(l i=0;i<n;i++){
        //so if there is a neighbouring '-' we can come back
        if(s[i]=='-'||s[i+1]=='-')res++;
        if(s[i]=='<')o=true;
        if(s[i]=='>')c=true;
    }
    if(!o||!c){//if there is only < or > we can complete full cycle so ans->n
        cout<<n<<endl;
    }else{
        cout<<res<<endl;
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
 