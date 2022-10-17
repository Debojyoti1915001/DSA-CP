// Debojyoti Das
//NIT Silchar
#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l left,right;
//    scanf("%ld",&left);
//    scanf("%ld",&right);
cin>>left>>right;
    l ans=0;
    for(l i=0;i<32;i++){
        for(l j=0;j<32;j++){
            //if(pow(3,i)>right||pow(5,j)>right)continue;
            l val=pow(3,i)*pow(5,j);
            if(val>=left&&val<=right){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    // printf("%ld",ans);
}
 
int main()
{
    int t = 1;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 