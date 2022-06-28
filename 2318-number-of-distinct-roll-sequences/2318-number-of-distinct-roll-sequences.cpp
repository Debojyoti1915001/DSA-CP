class Solution {
public:
    //an array of 
    int dp[10007][7][7]={};
    int mod=1e9+7;
    //prev-> previous element
    //pprev->previous of previous element
    int distinctSequences(int n,int prev=0,int pprev=0) {
        if(n==0)return 1;
        //if this is equal to 0 return since it is already being calculated
        if(dp[n][prev][pprev]!=0)return dp[n][prev][pprev]; 
        // now from 1 to 6 check 
        for(int i=1;i<=6;i++){
            //if it is not equal to prev or prev of prev element and gcd==1 somehow
            if(i!=prev&&i!=pprev&&(prev==0||__gcd(i,prev)==1))
                //add
            dp[n][prev][pprev]=(dp[n][prev][pprev]+distinctSequences(n-1,i,prev))%mod;
        }
        
        return dp[n][prev][pprev];
        
    }
};