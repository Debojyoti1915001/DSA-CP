class Solution {
public:
    int candy(vector<int>& v) {
        int n=v.size(),ans=0;
        vector<int> left(n,1),right(n,1);
        for(int i=1;i<n;i++){
            if(v[i]>v[i-1])left[i]=1+left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(v[i+1]<v[i])right[i]=1+right[i+1];
        }
        for(int i=0;i<n;i++)ans+=max(left[i],right[i]);
        return ans;
    }
};