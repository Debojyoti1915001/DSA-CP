// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
 
int main()
{
    int t = 1;
    // cin >> t;
    for (l i = 1; i <= t; i++)
    {
        l n;
        cin>>n;
        // cout<<n<<" ";
        // fun(n);
        vector<l>dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(i>=1)dp[i]+=dp[i-1];
            if(i>=3)dp[i]+=dp[i-3];
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}