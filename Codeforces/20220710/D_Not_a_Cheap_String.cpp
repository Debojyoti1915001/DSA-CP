// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   
   string s;
   cin>>s;
   l n;
   cin>>n;
   l cur=0;
   vector<l>cnt(26);
    for(auto c:s){
        cnt[c-'a']++;
        cur+=c-'a'+1;
    }
    l j=25;//z
    while(cur>n){
        // cout<<"yes"<<endl;
        if(cnt[j]==0){
            j--;
            continue;
        }
        l remove=(cur-n)/(j+1)+(((cur-n)%(j+1))?1:0);
        if(remove<=cnt[j]){
            cnt[j]-=remove;
            cur=n;
        }else{
            cur-=cnt[j]*(j+1);
            cnt[j]=0;
        }
        j--;
    }
    for(auto c:s){
        if(cnt[c-'a']!=0){
            cnt[c-'a']--;
            cout<<c;
        }
    }
    cout<<endl;
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
 