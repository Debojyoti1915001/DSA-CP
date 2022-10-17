#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
   cin>>n;
   vector<ll>vvv(n);
   map<ll,ll>m;
   ll cnt=0;
   for(ll i=0;i<n;i++){
    cin>>vvv[i];
    m[vvv[i]]++;
    if(m[vvv[i]]==2)cnt++;
   }
   ll rest=0;
   while(cnt){
    if(m[vvv[rest]]==2)cnt--;
    m[vvv[rest]]--;
    rest++;
   }
   cout<<rest<<endl;
    }
    return 0;
}
 