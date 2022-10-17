class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //Case-1: n<=1 OR k==0
        if(k==0 || n<=1)
            return 0;
        
        //Case-2: k>=n
        if(2*k>n)
        {
            int res = 0;
            for(int i=1;i<n;++i)
                if(prices[i]>prices[i-1])
                    res+=(prices[i]-prices[i-1]);
            return res;
        }
        
        //Case-3: 1<=k<n
        int dp[2*k+1];
        dp[0]=-prices[0];
        for(int i=1;i<=2*k;++i)
        {
            if(i%2==0)  //Buy
                dp[i]=INT_MIN;
            else    //SELL
                dp[i]=0;
        }
        
        for(int i=0;i<n;++i)
        for(int j=0;j<=2*k;++j)
        {
            if(j==0)
                dp[j]=max(dp[j],-prices[i]);
            else if(j%2==0)         //BUY
                dp[j]=max(dp[j],dp[j-1]-prices[i]);
            else                    //SELL
                dp[j]=max(dp[j],dp[j-1]+prices[i]);
        }
        return dp[2*k-1];
    }
};