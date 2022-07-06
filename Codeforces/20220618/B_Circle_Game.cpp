// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n;
   cin>>n;
   vector<l>v(n);
   set<l>s;
   l e=INT_MAX,o=INT_MAX;
   for(l i=0;i<n;i++){
    cin>>v[i];
    if(i%2==0)e=min(e,v[i]);
    else o=min(o,v[i]);
   }
    if(n%2==1){
        cout<<"Mike"<<endl;
    }else{
        if(o<e){
            cout<<"Mike"<<endl;
        }else if(o>e){
            cout<<"Joe"<<endl;
        }else{
            for(l i=0;i<n;i++){
                if(o==v[i]){
                    if(i%2==0){
                        cout<<"Joe"<<endl;
                    }else{
                        cout<<"Mike"<<endl;
                    }
                    break;
                }
            }
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
 