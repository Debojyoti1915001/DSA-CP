// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;

#define l long long int


const l mod = 1000000007;
const l N = 3e5, M = N;
int dp[1001][1001][2];
    int solve(string s,int i,int j,bool isTrue){
        if(i>j)return 0;
        if(i==j){
        if(isTrue==true)return s[i]=='T';   
        else return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
        int ans=0;
        int lT,lF,rT,rF;
        for(int k=i+1;k<=j-1;k+=2){
            if(dp[i][k-1][1]!=-1)lT=dp[i][k-1][true];
            else lT=solve(s,i,k-1,true);
            if(dp[i][k-1][0]!=-1)lF=dp[i][k-1][0];
            else lF=solve(s,i,k-1,false);
            if(dp[k+1][j][true]!=-1)rT=dp[k+1][j][true];
            else rT=solve(s,k+1,j,true);
            if(dp[k+1][j][false]!=-1)rF=dp[k+1][j][false];
            else rF=solve(s,k+1,j,false);
            if(s[k]=='&'){
                if(isTrue==true)ans=ans+lT*rT;
                else ans=ans+lT*rF+lF*rT+lF*rF;
            }
            else if(s[k]=='|'){
                if(isTrue==true)ans=ans+lT*rT+lF*rT+lT*rF;
                else ans=ans+lF*rF;
            }
            else if(s[k]=='^'){
                if(isTrue==true)ans=ans+lT*rF+lF*rT;
                else ans=ans+lT*rT+lF*rF;
            }
        }
        return dp[i][j][isTrue]=ans%1003;
    }
    int countWays(int n,string s){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n-1,true);
    }
void solve()
{
    string s;
    cin>>s;
    cout<<countWays(s.length(),s);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
