// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    l n;
    cin>>n;
    vector<l>v(10);
    for(l i=0;i<n;i++){
        l val;
        cin>>val;
        v[val%10]++;
    }
    l f=1;
    for(l i=0;i<=9&&f;i++){
        for(l j=0;j<=9&&f;j++){
            for(l k=0;k<=9&&f;k++){
            
              v[i]--;
                v[j]--;
                v[k]--;
                if(v[i]>=0&&v[j]>=0&&v[k]>=0&&(i+j+k)%10==3){
                    f=0;
                }
                v[i]++;
                v[j]++;
                v[k]++;
            }
        }
    }
    if(f==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
 