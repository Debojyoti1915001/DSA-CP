class Solution {
public:
    int solve(vector<int>temp,int k){
        int ans=INT_MIN;
        set<int>s;
        s.insert(0);
        int sum=0;
        for(int i:temp){
            sum+=i;
            auto lo=s.lower_bound(sum-k);
            if(lo!=s.end()){
                ans=max(ans,sum-*lo);
            }
            s.insert(sum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=INT_MIN;
        for(int l=0;l<m;l++){
            vector<int>temp(n);
            for(int r=l;r<m;r++){
                for(int i=0;i<n;i++){
                    temp[i]=temp[i]+mat[i][r];
                }
                // for(auto &i:temp)cout<<i<<" ";
                ans=max(ans,solve(temp,k));
                // cout<<ans<<endl;
            }
        }
        return ans;
    }
};