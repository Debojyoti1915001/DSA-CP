// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
bool check(string a){
    return a[0]==a[4]&&a[1]==a[3];
}
void solve()
{
    string s;
    l x;
    l ans=0;
    cin>>s>>x;
    string a=s;
    while(true){
        if(check(a)){
            ans++;
        }
        l inMinutes=((a[0]-'0')*10+a[1]-'0')*60+(a[3]-'0')*10+a[4]-'0';
        inMinutes+=x;
        inMinutes=inMinutes%(24*60);
        string hr=to_string(inMinutes/60);
        string mn=to_string(inMinutes%60);
        if(hr.size()==1)hr='0'+hr;
        if(mn.size()==1)mn='0'+mn;
        a=hr+':'+mn;
        if(a==s)break;
    }
    cout<<ans<<endl;
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
 