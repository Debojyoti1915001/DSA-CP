class Solution {
    public int[] findBall(int[][] g) {
        int n=g.length;
        int m=g[0].length;
        int dp[]=new int[m];
        if(m==1){
            dp[0]=-1;
            return dp;
        }
        for(int i=0;i<m;i++){
            dp[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[j]==0){
                   if(g[i][dp[j]]==1&&g[i][dp[j]+1]==1){
                       dp[j]=1;
                   }else{
                       dp[j]=-1;
                   } 
                }else if(dp[j]==m-1){
                    if(g[i][dp[j]]==-1&&g[i][dp[j]-1]==-1){
                       dp[j]=m-2;
                    }else{
                       dp[j]=-1;
                    }
                }else if(dp[j]!=-1){
                    if(g[i][dp[j]]==1&&g[i][dp[j]+1]==1){
                       dp[j]++;
                    }else if(g[i][dp[j]]==-1&&g[i][dp[j]-1]==-1){
                       dp[j]--;
                    }else{
                       dp[j]=-1;
                    } 
                }
            }
        }
        return dp;
    }
}