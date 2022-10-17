// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    string s;
    cin>>s;
    l o=0;
    vector<l>v;
    for(l i=0;i<s.size();i++){
        if(s[i]=='('){
            o++;
        }else if(s[i]==')'){
            o--;
            if(o<0){
                cout<<"NO"<<endl;
                return;
            }
        }else{
            if(o>0)o--;
            else o++;
        }
    }
    cout<<"YES"<<endl;

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
 