class Solution {
public:
    int minCost(string c, vector<int>& v) {
        int i=0,ans=0;
        int n=c.size();
        while(i<n){
            int j=i;
            int mx=v[j],sum=v[j];
            while(j<n-1&&c[j]==c[j+1]){
                j++;
                mx=max(mx,v[j]);
                sum+=v[j];
            }
            if(i!=j){
                ans+=sum-mx;
            }
            i=j+1;
        }
        return ans;
    }
};