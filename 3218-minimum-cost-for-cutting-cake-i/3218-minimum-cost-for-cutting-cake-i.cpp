class Solution {
public:
    int dp[25][25][25][25];
    int solve(int startH,int endH,int startV,int endV,vector<int>& h, vector<int>& v){
        if(startH >=endH||startV>=endV)return 0;
        if(endH-startH==1&&endV-startV==1)return 0;
        if(dp[startH][endH][startV][endV]!=-1)return dp[startH][endH][startV][endV];
        int ans=INT_MAX;
        for(int i=startH+1;i<endH;i++){
            int cost=h[i-1];
            ans=min(ans,solve(startH,i,startV,endV,h,v)+solve(i,endH,startV,endV,h,v)+cost);
        }
        for(int i=startV+1;i<endV;i++){
            int cost=v[i-1];
            ans=min(ans,solve(startH,endH,startV,i,h,v)+solve(startH,endH,i,endV,h,v)+cost);
        }
        return dp[startH][endH][startV][endV]=ans;
    }
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        return solve(0,m,0,n,h,v);
    }
};