class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n=m.size(),ans=-1;
        int lo=m[0][0],hi=m[n-1][n-1];
        while(lo<=hi){
            int mid=(hi-lo)/2+lo;
            int cnt=0;
            for(auto i:m){
                cnt+=upper_bound(i.begin(),i.end(),mid)-i.begin();
                if(cnt==0)break;
            }
            if(cnt<k){
                lo=mid+1;
            }else{
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }
};