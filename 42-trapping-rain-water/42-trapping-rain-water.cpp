class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        if(n==0)return 0;
        vector<int>mxr(n),mxl(n);
        mxr[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--)mxr[i]=max(mxr[i+1],v[i]);
        mxl[0]=v[0];
        for(int i=1;i<n;i++)mxl[i]=max(mxl[i-1],v[i]);
        int ans=0;
        for(int i=0;i<n;i++)ans+=min(mxl[i],mxr[i])-v[i];
        return ans;
    }
};