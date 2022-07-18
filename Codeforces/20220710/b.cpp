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
    for(l i=0;i<n;i++)cin>>v[i];
    for(l i=0;i<n;i++){
        if(v[i]<0){
            l j=i;
            while(j!=0&&v[j-1]>0){
                l temp=v[j-1];
                v[j-1]=v[j];
                v[j]=temp;
                j--;
            }
        }
    }
    for(auto x:v){
        cout<<x<<" ";
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
 