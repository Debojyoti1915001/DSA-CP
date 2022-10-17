// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
 int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
void solve()
{
    int n;
    cin>>n;
    vector<string>v(n);
    for(auto &i:v)cin>>i;
    string s;
    cin>>s;
    int mn=INT_MAX;
    string ans;
    
    for(auto &i:v){
        int cur=i.size()+s.size()-longestCommonSubsequence(i,s);
         if(cur<=mn){
            if(ans.size()){
                ans=min(ans,i);
            }else{
                ans=i;
            }
            mn=min(mn,cur);
         }
    }
    cout<<ans<<endl;
}
 
int main()
{
    solve();
    return 0;
}
 