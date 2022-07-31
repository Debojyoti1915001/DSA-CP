class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        int c1=0,c2=0,c3=0;//we contain 3 pointers all of which points to 0 initially
        dp[0]=1;
        for(int i=1;i<n;i++){
            //since only factors of 2,3,5 are considered
            dp[i]=min({2*dp[c1],3*dp[c2],5*dp[c3]});
            if(dp[i]==2*dp[c1])c1++;
            if(dp[i]==3*dp[c2])c2++;
            if(dp[i]==5*dp[c3])c3++;
        }
        return dp[n-1];
    }
};