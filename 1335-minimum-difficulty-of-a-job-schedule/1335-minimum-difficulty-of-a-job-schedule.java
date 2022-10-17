class Solution {
    
    public int minDifficulty(int[] v, int d) {
        final int n=v.length;
        if(n<d)return -1;
        int dp[][]=new int[n][d+1];
        for(int []i:dp)Arrays.fill(i,-1);
        return dfs(0,d,v,dp);
    }
    private int dfs(int len,int d,int[] v,int [][]dp){
        final int n=v.length;
        if(len==n&&d==0)return 0;
        if(len==n||d==0)return Integer.MAX_VALUE;
        if(dp[len][d]!=-1)return dp[len][d];
        int min=Integer.MAX_VALUE;
        int curMax=v[len];
        for(int sch=len;sch<n;sch++){
            curMax=Math.max(curMax,v[sch]);
            int temp=dfs(sch+1,d-1,v,dp);
            // System.out.println(temp);
            if(temp!=Integer.MAX_VALUE){
                min=Math.min(temp+curMax,min);
            }
        }
        
        return dp[len][d]=min;
    }
}