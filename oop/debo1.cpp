// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    string s;
    cin>>s;
    string a,b,c;
    l k=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'||s[i]=='=')k++;
        else if(k==0)a+=s[i];
        else if(k==1)b+=s[i];
        else if(k==2)c+=s[i];
    }
    if(c=="X")cout<<stoi(a)+stoi(b)<<endl;
    if(a=="X")cout<<stoi(c)-stoi(b)<<endl;
    if(b=="X")cout<<stoi(c)-stoi(a)<<endl;
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
 