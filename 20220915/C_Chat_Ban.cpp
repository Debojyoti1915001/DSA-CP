// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
    
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(S[i]=='a'&&S[j]=='b')res++;
        }
    }
    return res;


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
 