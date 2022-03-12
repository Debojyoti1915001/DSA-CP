class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int>cnt(n,1);
        int mx=1;
        sort(pairs.begin(),pairs.end());
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(pairs[i][1]<pairs[j][0]&&cnt[j]+1>cnt[i]){
                    cnt[i]=cnt[j]+1;
                    mx=max(mx,cnt[i]);
                }
            }
        }
        return mx;
    }
};