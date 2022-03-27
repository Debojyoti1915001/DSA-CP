class Solution {
public:
    int count(vector<int> v,int n,int M){
        int t[n+1][M+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=M;j++){
                if(i==0)t[i][j]=0;
                if(j==0)t[i][j]=1;
            }
        }
          for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= M; j++)
            {
                if(v[i - 1] <= j)
                 t[i][j] = t[i - 1][j - v[i - 1]] + t[i - 1][j];
                else
                  t[i][j] = t[i - 1][j];
            }
        }
        
        return t[n][M];
        
    }
    int findTargetSumWays(vector<int>& v, int target) {
        int n=v.size();
        int sum=0;
        //S1-S2=target
        //S1+S2=Sum
        //S1=(Sum+target)/2
        if(target<0)target=target*(-1);
        for(int i=0;i<n;i++)sum+=v[i];
        int M=(target+sum)/2;
        if(sum<target||(target+sum)%2)return 0;
            return count(v,n,M);
    }
};